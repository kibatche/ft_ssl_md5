#include "ft_ssl.h"

extern char *message;

static int md5_state(int i)
{
    if (i <= 15) return ROUND_1;
    else if (i <= 31) return ROUND_2;
    else if (i <= 47) return ROUND_3;
    else if (i <= 63) return ROUND_4;
    return -1;
}

void md5_sum()
{
    unsigned int len = ft_strlen(message);
    // the k constant (for i from 0 to 63 do K[i] := floor(232 × abs(sin(i + 1))) end for)
    const uint32_t K[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340,	0x265e5a51,	0xe9b6c7aa,	0xd62f105d,	0x02441453,	0xd8a1e681,	0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

    //the S constant, for shifting
    const uint32_t S[64] = {
        7, 12, 17, 22, 7, 12, 17, 22,  7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20,  5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23,  4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21,  6, 10, 15, 21, 6, 10, 15, 21
    };

    //32-bits words constants
    uint32_t A = 0x67452301;
    uint32_t B = 0xEFCDAB89;
    uint32_t C = 0x98BADCFE;
    uint32_t D = 0x10325476;

    int padded_message_len = 0;

    uint8_t *padded_message = pad_message(message, len, &padded_message_len);
    chunked_message *chunked_msg_array = split_message_into_chuncks_md5(padded_message, padded_message_len);
    int number_of_chunks = padded_message_len / 64;

    for (int n = 0; n < number_of_chunks; n++)// n is the index inside the chunked message array
    {
        uint32_t a_cpy = A;
        uint32_t b_cpy = B;
        uint32_t c_cpy = C;
        uint32_t d_cpy = D;
        for (uint32_t i = 0; i < 64; i++)
        {
            uint32_t f = 0;
            uint32_t g = 0;
            switch(md5_state(i)) {
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
                    REEF(message);
                    REEF(padded_message);
                    REEF(chunked_msg_array->word);
                    REEF(chunked_msg_array);
                    print_error("Wrong state inside the function state(). You should check the variable i.");
                    break;
            };
            f = f + a_cpy + K[i] + chunked_msg_array[n].word[g];
            a_cpy = d_cpy;
            d_cpy = c_cpy;
            c_cpy = b_cpy;
            b_cpy = b_cpy + ROTL(f, S[i]);
        }
        A += a_cpy;
        B += b_cpy;
        C += c_cpy;
        D += d_cpy;
    }
    printf("%x%x%x%x\n", bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
    REEF(message);
    REEF(padded_message);
    REEF(chunked_msg_array->word);
    REEF(chunked_msg_array);
}
