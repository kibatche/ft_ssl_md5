#include "ft_ssl.h"

extern programm_info p_info;
extern char *message;
extern char *current_processed_filename;

char *change_newline()
{
    int i = -1;
    int j = 0;
    unsigned int len = 0;
    char *str = NULL;
    
    while (++i < ft_strlen(message))
    {
        if (message[i] == '\n' || message[i] == '\r')//yeah...
            len++;
    }
    len += i;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
    {
        REEF(message);
        print_error(ERR_MALLOC);
    }
    i = -1;
    while (++i < ft_strlen(message))
    {
        if (message[i] == '\n')
        {
            ft_strcat(str, "\\n");
            j += 2;
            continue;
        }
        else if (message[i] == '\r')
        {
            ft_strcat(str, "\\r");
            j += 2;
            continue;
        }
        str[j++] = message[i];
    }
    return str;
}

void print_md5_hash(uint32_t A, uint32_t B, uint32_t C, uint32_t D)
{
    char *to_print = NULL;

    switch (p_info.handle_mode)
    {
        case STDIN_ONLY_HANDLE_MODE:
                if (p_info.quiet_option)
                {
                    printf("%08x%08x%08x%08x\n",\
                        bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
                    break;
                }
                else if (p_info.reverse_option)
                {
                    printf("%08x%08x%08x%08x stdin\n", \
                        bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));    
                    break;
                }
                printf("MD5(stdin)= %08x%08x%08x%08x\n", \
                        bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
                break;
        case STDIN_COMMAND_LINE_HANDLE_MODE:
                if (p_info.quiet_option)//examples provided are not coherent. -p is not affected by -r or by -q but direct stdin, yes...
                {
                    printf("%s %08x%08x%08x%08x\n", message, \
                        bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
                    break;
                }
                to_print = change_newline();
                printf("(\"%s\")= %08x%08x%08x%08x\n", to_print, \
                    bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
                REEF(to_print);
                break;
        case STRING_HANDLE_MODE:
                if (p_info.quiet_option)
                {
                    printf("%08x%08x%08x%08x\n",\
                        bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
                    break;
                }
                if (p_info.reverse_option)
                {
                    to_print = change_newline();
                    printf("%08x%08x%08x%08x \"%s\"\n", \
                        bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D), \
                        to_print);
                    REEF(to_print);
                    break;
                }
                to_print = change_newline();
                printf("MD5(\"%s\")= %08x%08x%08x%08x\n", to_print, \
                    bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
                REEF(to_print);
        case FILE_HANDLE_MODE:
                if (p_info.quiet_option)
                {
                    printf("%08x%08x%08x%08x\n",\
                        bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
                    break;
                }
                if (p_info.reverse_option)
                {
                    printf("%08x%08x%08x%08x \"%s\"\n", \
                        bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D), \
                        current_processed_filename);
                    REEF(to_print);
                    break;
                }
                printf("MD5(\"%s\")= %08x%08x%08x%08x\n", current_processed_filename, \
                    bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
        default:
            break;
    }
}

void print_sha256_hash(uint32_t h0, uint32_t h1, uint32_t h2, uint32_t h3, uint32_t h4, uint32_t h5, uint32_t h6, uint32_t h7)
{
    char *to_print = NULL;

    switch (p_info.handle_mode)
    {
        case STDIN_ONLY_HANDLE_MODE:
                if (p_info.quiet_option)
                {
                    printf("%08x%08x%08x%08x%08x%08x%08x%08x\n",\
                        h0, h1, h2, h3, h4, h5, h6, h7);
                    break;
                }
                else if (p_info.reverse_option)
                {
                    printf("%08x%08x%08x%08x%08x%08x%08x%08x stdin\n", \
                        h0, h1, h2, h3, h4, h5, h6, h7);    
                    break;
                }
                printf("SHA256(stdin)= %08x%08x%08x%08x%08x%08x%08x%08x\n", \
                        h0, h1, h2, h3, h4, h5, h6, h7);
                break;
        case STDIN_COMMAND_LINE_HANDLE_MODE:
                if (p_info.quiet_option)//examples provided are not coherent. -p is not affected by -r or by -q but direct stdin, yes...
                {
                    printf("%s %08x%08x%08x%08x%08x%08x%08x%08x\n", message, \
                        h0, h1, h2, h3, h4, h5, h6, h7);
                    break;
                }
                to_print = change_newline();
                printf("(\"%s\")= %08x%08x%08x%08x%08x%08x%08x%08x\n", to_print, \
                    h0, h1, h2, h3, h4, h5, h6, h7);
                REEF(to_print);
                break;
        case STRING_HANDLE_MODE:
                if (p_info.quiet_option)
                {
                    printf("%08x%08x%08x%08x%08x%08x%08x%08x\n",\
                        h0, h1, h2, h3, h4, h5, h6, h7);
                    break;
                }
                if (p_info.reverse_option)
                {
                    to_print = change_newline();
                    printf("%08x%08x%08x%08x%08x%08x%08x%08x \"%s\"\n", \
                        h0, h1, h2, h3, h4, h5, h6, h7, \
                        to_print);
                    REEF(to_print);
                    break;
                }
                to_print = change_newline();
                printf("SHA256(\"%s\")= %08x%08x%08x%08x%08x%08x%08x%08x\n", to_print, \
                    h0, h1, h2, h3, h4, h5, h6, h7);
                REEF(to_print);
        case FILE_HANDLE_MODE:
                if (p_info.quiet_option)
                {
                    printf("%08x%08x%08x%08x%08x%08x%08x%08x\n",\
                        h0, h1, h2, h3, h4, h5, h6, h7);
                    break;
                }
                if (p_info.reverse_option)
                {
                    printf("%08x%08x%08x%08x%08x%08x%08x%08x \"%s\"\n", \
                        h0, h1, h2, h3, h4, h5, h6, h7, \
                        current_processed_filename);
                    REEF(to_print);
                    break;
                }
                printf("SHA256(\"%s\")= %08x%08x%08x%08x%08x%08x%08x%08x\n", current_processed_filename, \
                    h0, h1, h2, h3, h4, h5, h6, h7);
        default:
            break;
    }
}
