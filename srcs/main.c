#include "ft_ssl.h"

programm_info p_info = {NO_HASH_MODE, false, false, false, false, NO_HANDLE_MODE};
hash_function h_functions[NUMBER_OF_HASH_FUNCTIONS] = {md5_sum, sha256_sum};
char *message = NULL;

int main(int ac, char **av)
{
    if (check_current_machine_endianess() == BENDIAN)
        print_error("This program must be run on a LITTLE ENDIAN system. Wait the PRO version for BIG ENDIAN.\n");
    parse_arg(ac, av);
    return 0;
}
