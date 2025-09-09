#ifndef DEFS_H
# define DEFS_H

# include <stdint.h>

typedef struct t_chunked_message {
    uint32_t *word;
}               chunked_message;

typedef bool OPTION;
typedef void (*hash_function)(unsigned int);

enum PARSING_STATE {
    NO_STATE,
    OPTION_STATE,
    STRING_STATE,
    FILE_STATE
};

enum HASH_MODE {
    MD5_HASH_MODE,
    SHA256_HASH_MODE,
    NO_HASH_MODE,
};

enum HANDLE_MODE {
    NO_HANDLE_MODE,
    STDIN_COMMAND_LINE_HANDLE_MODE,
    STDIN_ONLY_HANDLE_MODE,
    FILE_HANDLE_MODE,
    STRING_HANDLE_MODE,
};

typedef struct  t_programm_info
{
    enum HASH_MODE hash_mode;
    OPTION string_option;
    OPTION quiet_option;
    OPTION reverse_option;
    OPTION print_stdin_option;
    enum HANDLE_MODE handle_mode;
}               programm_info;

#endif
