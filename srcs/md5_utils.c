#include "ft_ssl.h"



uint32_t md5_split_chunk_into_word(uint32_t one, uint32_t two, uint32_t three, uint32_t four)
{
    return ((four << 24) | (three << 16) | (two << 8)  | one);//little endian => https://stackoverflow.com/questions/53289526/c-convert-four-unsined-chars-to-one-unsigned-int 
}

chunked_message *md5_split_message_into_chuncks(uint8_t *padded_message, int lenOfPadded_message)
{
    // we need to chunk the msg by 64 bytes blocks.
    // but we don't need the chunks, only the words inside the chunks for md5.
    int k = 0;
    chunked_message *chunk_array = malloc(sizeof(chunked_message) * (lenOfPadded_message / 64));
    if (chunk_array == NULL) print_error("malloc failed.\n");
    for (int i = 0; i < (lenOfPadded_message / 64); i++)
    {
        for (int j = 0; j < 16; j++)
        {
            chunk_array[i].word[j] = md5_split_chunk_into_word( \
                (uint32_t)padded_message[k], \
                (uint32_t)padded_message[k + 1], \
                (uint32_t)padded_message[k + 2], \
                (uint32_t)padded_message[k + 3]);
            k += 4;
        }
    }
    return chunk_array;
}

int md5_state(int i)
{
    if (i <= 15) return ROUND_1;
    else if (i <= 31) return ROUND_2;
    else if (i <= 47) return ROUND_3;
    else if (i <= 63) return ROUND_4;
    return -1;
}