#include "ft_ssl.h"

// the k constant (for i from 0 to 63 do K[i] := floor(232 × abs(sin(i + 1))) end for)
const unsigned int K[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340,	0x265e5a51,	0xe9b6c7aa,	0xd62f105d,	0x02441453,	0xd8a1e681,	0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

//the S constant
const unsigned int S[64] = {
    7, 12, 17, 22, 7, 12, 17, 22,  7, 12, 17, 22, 7, 12, 17, 22,
    5,  9, 14, 20, 5,  9, 14, 20,  5,  9, 14, 20, 5,  9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23,  4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21,  6, 10, 15, 21, 6, 10, 15, 21 
};




uint8_t *md5_padding(uint8_t *message, int len, int *final_len_byte)
{
    unsigned int lenBit = len * 8;// 1 char == 8 bits
    unsigned int paddingLenBit = 1; // add 1 to the message

    while ((paddingLenBit % 512) != 448) paddingLenBit++;
    uint8_t *padded_message = malloc(sizeof(char) * ((lenBit + paddingLenBit + 64) / 8));//we need the size in byte, not in bit
    if (padded_message == NULL)
        print_error("malloc failed.\n");
    ft_memcpy(padded_message, message, len);
// we add the bit '1' to the message
    padded_message[len++] = 0x80;
// we fill the msg up to len + paddingLenBit - 1 to the msg, because we have already inserted the bit "1" to the msg
    ft_memset(padded_message + len, 0, (paddingLenBit - 1));
// we add the original len to the msg in 64bits to have a perfect multiple of 512.
    ft_memset(padded_message + len + (paddingLenBit - 1), (uint64_t)(len - 1), sizeof(uint64_t));
    *final_len_byte = ((len - 1) + paddingLenBit + 8) / 8;// len in byte not in bit
    return padded_message;
}

unsigned int *split_chunk_into_word(uint8_t one, uint8_t two, uint8_t three, uint8_t four)
{
    return (four << 24) | (three << 16) | (two << 8) | one;//little endian => https://stackoverflow.com/questions/53289526/c-convert-four-unsined-chars-to-one-unsigned-int 
}

chunked_message *split_message_into_chuncks(uint8_t *padded_message, int lenOfPadded_message)
{
    int k = 0;
    chunked_message *chunked_array = malloc(sizeof(chunked_message) * (lenOfPadded_message / 64));
    if (chunked_array == NULL)
        print_error("malloc failed.\n");
    for (int i = 0; i < (lenOfPadded_message / 64); i++)
    {
        for (int j = 0; j < 16; j++)
        {
            chunked_array[i].word[j] = split_chunk_into_word(padded_message[k], padded_message[k + 1], padded_message[k + 2], padded_message[k + 3]);
            k += 4;
        }
    }
    return chunked_array;
}

int state(int i)
{
    if (i >= 0 && i <= 15) return ROUND_1;
    else if (i >= 16 && i <= 31) return ROUND_2;
    else if (i >= 32 && i <= 47) return ROUND_3;
    else if (i >= 48 && i <= 64) return ROUND_4;
    return -1;
}

// https://en.wikipedia.org/wiki/Circular_shift
uint32_t rotate_left(uint32_t val, uint32_t count)
{
    const unsigned int mask = CHAR_BIT * sizeof(val) - 1;
    count = count & mask; // I prefer this 'cause i do not know much about bitwise op and it's clearer for me
    return ((val >> count) | (val >> (-count & mask)));
}

char *md5_sum(uint8_t *message, unsigned int len)
{
    //32-bits words constants
    uint32_t A = 0x67452301;
    uint32_t B = 0xEFCDAB89;
    uint32_t C = 0x98BADCFE;
    uint32_t D = 0x10325476;
    int final_len_byte = 0;
    uint8_t *padded_message = md5_padding(message, len, &final_len_byte);
    chunked_message *chunked_msg_array = split_message_into_chuncks(padded_message, final_len_byte);

    for (int n = 0; n < (final_len_byte / 64); n++)// n is the index inside the chunked message array
    {
        unsigned int a_cpy = A;
        unsigned int b_cpy = B;
        unsigned int c_cpy = C;
        unsigned int d_cpy = D;
        for (int i = 0; i < 64; i++)
        {
            int f;
            int g;
            switch(state(i)) {
                case ROUND_1:
                    f = F(b_cpy, c_cpy, d_cpy);
                    g = i;
                    break;
                case ROUND_2:
                    f = G(b_cpy, c_cpy, d_cpy);
                    g = (5 * i + 1) % 16;
                    break;
                case ROUND_3:
                    f = H(b_cpy, c_cpy, d_cpy);
                    g = (3 * i + 5) % 16;
                    break;
                case ROUND_4:
                    f = I(b_cpy, c_cpy, d_cpy);
                    g = (7 * i) % 16;
                    break;
                default:
                    REEF(padded_message);
                    print_error("Wrong state inside the function state(). You should check the variable i.");
            };
            f = f + a_cpy + K[i] + chunked_msg_array[n].word[g];
            a_cpy = d_cpy;
            d_cpy = c_cpy;
            c_cpy = b_cpy;
            b_cpy = b_cpy + rotate_left(f, S[i]);
        }
        A += a_cpy;
        B += b_cpy;
        C += c_cpy;
        D += d_cpy;
    }
    char *first_digest = ft_itoa_base(A, 16);
    char *second_digest = ft_itoa_base(B, 16);
    char *third_digest = ft_itoa_base(C, 16);
    char *fourth_digest = ft_itoa_base(D, 16);
    printf("%s%s%s%s\n", first_digest, second_digest, third_digest, fourth_digest);
}