#include "ft_ssl.h"

extern char *message;

chunked_message *split_message_into_chuncks_md5(uint8_t *padded_message, int padded_message_len)
{
    // we need to chunk the msg by 64 bytes blocks.
    // but we don't need the chunks, only the words inside the chunks for md5 and sha256.
    int k = 0;
    chunked_message *chunk_array = malloc(sizeof(chunked_message) * (padded_message_len / 64));
    if (chunk_array == NULL)
    {
        REEF(message);
        print_error("malloc failed.\n");
    }

    for (int i = 0; i < (padded_message_len / 64); i++)
    {
        chunk_array[i].word = malloc(sizeof(uint32_t) * 16);
        if (chunk_array[i].word == NULL)
        {
            for (int l = 0; l < i; l++)
            {
                REEF(chunk_array[l].word);
            }
            REEF(message);
            print_error("malloc failed.\n");
        }
        for (int j = 0; j < 16; j++)
        {
            chunk_array[i].word[j] = split_chunk_into_word_little_endian( \
                (uint32_t)padded_message[k],     \
                (uint32_t)padded_message[k + 1], \
                (uint32_t)padded_message[k + 2], \
                (uint32_t)padded_message[k + 3]  \
            );
            k += 4;
        }
    }
    return chunk_array;
}