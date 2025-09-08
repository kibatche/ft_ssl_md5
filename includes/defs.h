#ifndef DEFS_H
# define DEFS_H

# include <stdint.h>

typedef struct t_chunked_message {
    uint32_t *word;
}               chunked_message;

typedef void (*crypto_function)(unsigned int);

typedef struct t_ssl_config {
    crypto_function fun;
    char *fun_name;
}               ssl_config;

typedef bool OPTION;

enum PARSING_STATE {
    NO_STATE,
    OPTION_STATE,
    STRING_STATE,
    FILE_STATE
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
    ssl_config *ssl_conf;
    OPTION string_option;
    OPTION quiet_option;
    OPTION reverse_option;
    OPTION print_stdin_option;
    enum HANDLE_MODE handle_mode;
}               programm_info;

#endif
