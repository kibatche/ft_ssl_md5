#ifndef FT_SSL_H
# define  FT_SSL_H

# include <byteswap.h>
# include <endian.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "defs.h"
# include "consts.h"
# include "libft.h"
# include "macros.h"

//parsing
void parse_hash_mode(char *hash_mode);
void parse_arg(int ac, char **av);
char *parse_stdin();
char *parse_file(char *path);
enum PARSING_STATE file_state_parsing(char *token);
enum PARSING_STATE string_state_parsing(char *token);
enum PARSING_STATE no_state_parsing(char *token);

//md5
void md5_sum();
chunked_message *split_message_into_chuncks_md5(uint8_t *padded_message, int padded_message_len);

//sha256
void sha256_sum();
chunked_message *split_message_into_chuncks_sha256(uint8_t *padded_message, int padded_message_len);

//utils for both md5 and sha256 hash functions but not really super specifics (subject to change)
uint8_t *pad_message(uint8_t *message, int len, int *final_len_byte);
uint32_t split_chunk_into_word_little_endian(uint32_t one, uint32_t two, uint32_t three, uint32_t four);
uint32_t split_chunk_into_word_big_endian(uint32_t one, uint32_t two, uint32_t three, uint32_t four);

//generic utils
int check_current_machine_endianess();

//errors
void print_error(char *error_message);

#endif
