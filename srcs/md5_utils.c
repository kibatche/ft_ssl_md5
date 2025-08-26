#include "ft_ssl.h"

//P is what we add after the message. It will never have more than 64 values
const uint32_t P[64] = {
    128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

uint8_t *md5_padding(uint8_t *message, int len, int *final_len_byte)
{
    uint32_t remaining = len % 64;
    uint32_t paddingLen = 0;
    if (remaining > 56)
        paddingLen = 56 - (64 - remaining);
    else
        paddingLen = 56 - remaining;
    *final_len_byte = len + paddingLen + 8;// len in byte not in bit
    uint8_t *padded_message = malloc(sizeof(char) * (*final_len_byte));
    if (padded_message == NULL)
        print_error("malloc failed.\n");
    uint64_t len64 = (uint64_t)len;
    ft_memcpy(padded_message, message, len);
// we add the bit '1' to the message + the '0'
    ft_memcpy(padded_message + len, P, paddingLen);
// we add the original len to the msg in 64bits to have a perfect multiple of 512.
    ft_memcpy(padded_message + len + paddingLen, &len64, sizeof(uint64_t));
    return padded_message;
}

uint32_t split_chunk_into_word(uint32_t one, uint32_t two, uint32_t three, uint32_t four)
{
    return ((four << 24) | (three << 16) | (two << 8)  | one);//little endian => https://stackoverflow.com/questions/53289526/c-convert-four-unsined-chars-to-one-unsigned-int 
}

chunked_message *split_message_into_chuncks(uint8_t *padded_message, int lenOfPadded_message)
{
    // we need to chunk the msg by 64bytes blocks.
    // we don't really need the chunks, only the words inside the chunk for md5.
    int k = 0;
    chunked_message *chunk_array = malloc(sizeof(chunked_message) * (lenOfPadded_message / 64));
    if (chunk_array == NULL) print_error("malloc failed.\n");
    for (int i = 0; i < (lenOfPadded_message / 64); i++)
    {
        for (int j = 0; j < 16; j++)
        {
            chunk_array[i].word[j] = split_chunk_into_word( \
                (uint32_t)padded_message[k], \
                (uint32_t)padded_message[k + 1], \
                (uint32_t)padded_message[k + 2], \
                (uint32_t)padded_message[k + 3]);
            k += 4;
        }
    }
    return chunk_array;
}

int state(int i)
{
    if (i <= 15) return ROUND_1;
    else if (i <= 31) return ROUND_2;
    else if (i <= 47) return ROUND_3;
    else if (i <= 63) return ROUND_4;
    return -1;
}

// https://en.wikipedia.org/wiki/Circular_shift
uint32_t rotate_left(uint32_t val, uint32_t count)
{
    const uint32_t mask = CHAR_BIT * sizeof(val) - 1;
    count = count & mask; // I prefer this 'cause i do not know much about bitwise op and it's clearer for me
    return ((val << count) | (val >> (-count & mask)));
}