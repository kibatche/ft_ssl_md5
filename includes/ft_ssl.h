#ifndef FT_SSL_H
# define  FT_SSL_H

# include <endian.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "consts.h"
# include "libft.h"
# include "macros.h"

typedef struct t_chunked_message {
    uint32_t *word;
}               chunked_message;

//md5
void md5_sum(uint8_t *message, uint32_t len);
chunked_message *split_message_into_chuncks_md5(uint8_t *padded_message, int padded_message_len);

//sha256
void sha256_sum(uint8_t *message, uint32_t len);
chunked_message *split_message_into_chuncks_sha256(uint8_t *padded_message, int padded_message_len);
int sha256_state(int i);

//utils for both md5 and sha256 hash functions but not really super specifics (subject to change)
uint8_t *pad_message(uint8_t *message, int len, int *final_len_byte);
uint32_t split_chunk_into_word_little_endian(uint32_t one, uint32_t two, uint32_t three, uint32_t four);
uint32_t split_chunk_into_word_big_endian(uint32_t one, uint32_t two, uint32_t three, uint32_t four);

//generic utils
int check_current_machine_endianess();

//errors
void print_error(char *error_message);

#endif