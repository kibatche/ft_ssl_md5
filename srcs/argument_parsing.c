#include "ft_ssl.h"

extern programm_info p_info;
extern hash_function h_functions[NUMBER_OF_HASH_FUNCTIONS];
extern char *message;

void parse_hash_mode(char *hash_mode)
{
    if (strcmp(hash_mode, MD5_STRING) == 0)         p_info.hash_mode = MD5_HASH_MODE;
    else if (strcmp(hash_mode, SHA256_STRING) == 0) p_info.hash_mode = SHA256_HASH_MODE;
    print_error(ERR_USAGE);
}

enum PARSING_STATE no_state_parsing(char *token)
{
    int ret;
    char *buffer;
    char *line;
    unsigned int len;

    if (strcmp(token, "-p") == 0)
    {
        if (p_info.print_stdin_option == true) print_error(ERR_USAGE);
        p_info.print_stdin_option = true;
        while ((ret = get_next_line(1, &line)) >= 0)
        {
            if (ret == 0)
            {
                message = ft_strjoin(buffer, line);
                REEF(buffer);
                REEF(line);
                h_functions[p_info.hash_mode]();
                REEF(message);
                return NO_STATE;
            }
            REEF(message);
        }
        REEF(message);
    }
    if (strcmp(token, "-s") == 0)
    {
        if (p_info.string_option == true) print_error(ERR_USAGE);
        p_info.string_option = true;
        return ARGUMENT_STATE;
    }
}

void parse_arg(int ac, char **av)
{
    enum PARSING_STATE parsing_state = NO_STATE;
    int i = 2;

    if (ac == 1) print_error(ERR_USAGE);
    parse_hash_mode(av[1]);
    while (i < ac)
    {
        switch (parsing_state)
        {
        case NO_STATE:
            /* code */
            break;

        default:
            break;
        }

    }
}
