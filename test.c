void print_SHA256_hash(uint32_t A, uint32_t B, uint32_t C, uint32_t D)
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
                printf("SHA256(stdin)= %08x%08x%08x%08x\n", \
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
                printf("SHA256(\"%s\")= %08x%08x%08x%08x\n", to_print, \
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
                printf("SHA256(\"%s\")= %08x%08x%08x%08x\n", current_processed_filename, \
                    bswap_32(A), bswap_32(B), bswap_32(C), bswap_32(D));
        default:
            break;
    }
}