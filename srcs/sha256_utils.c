#include "ft_ssl.h"

chunked_message *split_message_into_chuncks_sha256(uint8_t *padded_message, int padded_message_len)
{
    // we need to chunk the msg by 64 bytes blocks.
    // but we don't need the chunks, only the words inside the chunks for md5 and sha256.
    int k = 0;
    
    chunked_message *chunk_array = malloc(sizeof(chunked_message) * (padded_message_len / 64));
    if (chunk_array == NULL) print_error("malloc failed.\n");
    
    chunk_array->word = malloc(sizeof(uint32_t) * 64);
    if (chunk_array->word == NULL) print_error("malloc failed.\n");

    for (int i = 0; i < (padded_message_len / 64); i++)
    {
        // page 22 from NIST.FIPS.180-4.pdf
        // first ( 0 <= j <= 15) we copy the values from the chunk
        for (int j = 0; j < 16; j++)
        {
            chunk_array[i].word[j] = split_chunk_into_word_big_endian( \
                (uint32_t)padded_message[k],     \
                (uint32_t)padded_message[k + 1], \
                (uint32_t)padded_message[k + 2], \
                (uint32_t)padded_message[k + 3]  \
            );
            k += 4;
        }
        // then (16 <= j <= 63) we mix values from previous words inside the chunks.
        for (int j = 16; j < 64; j++)
        {
            chunk_array[i].word[j] =          \
            s1(chunk_array[i].word[j - 2])  + \
            chunk_array[i].word[j - 7]      + \
            s0(chunk_array[i].word[j - 15]) + \
            chunk_array[i].word[j - 16];
        }
    }
    return chunk_array;
}