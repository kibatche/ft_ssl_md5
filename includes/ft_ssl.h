#ifndef FT_SSL_H
# define  FT_SSL_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "libft.h"
# include "consts.h"

typedef struct t_chunked_message {
    uint32_t word[16];
}               chunked_message;

char *md5_sum(uint8_t *message, uint32_t len);
uint8_t *md5_padding(uint8_t *message, int len, int *final_len_byte);
chunked_message *split_message_into_chuncks(uint8_t *padded_message, int lenOfPadded_message);
uint32_t split_chunk_into_word(uint32_t one, uint32_t two, uint32_t three, uint32_t four);
int state(int i);
uint32_t rotate_left(uint32_t val, uint32_t count);
void print_error(char *errMsg);

#endif