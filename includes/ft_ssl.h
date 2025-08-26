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

//md5
char *md5_sum(uint8_t *message, uint32_t len);
chunked_message *md5_split_message_into_chuncks(uint8_t *padded_message, int lenOfPadded_message);
uint32_t md5_split_chunk_into_word(uint32_t one, uint32_t two, uint32_t three, uint32_t four);
int md5_state(int i);

//sha256
char *sha256_sum(uint8_t *message, uint32_t len);
uint8_t *sha256_padding(uint8_t *message, int len, int *final_len_byte);
chunked_message *sha256_split_message_into_chuncks(uint8_t *padded_message, int lenOfPadded_message);
uint32_t sha256_split_chunk_into_word(uint32_t one, uint32_t two, uint32_t three, uint32_t four);
int sha256_state(int i);

//sha256
char *sha256_sum(uint8_t *message, uint32_t len);

//algo utils
uint8_t *padding(uint8_t *message, int len, int *final_len_byte);

//bitwise utils
uint32_t rotate_left(uint32_t val, uint32_t count);
uint32_t rotate_right(uint32_t val, uint32_t count);

//errors
void print_error(char *errMsg);

#endif