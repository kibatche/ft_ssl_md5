#include "ft_ssl.h"

programm_info p_info = {NO_HASH_MODE, false, false, false, false, NO_HANDLE_MODE};
hash_function h_functions[NUMBER_OF_HASH_FUNCTIONS] = {md5_sum, sha256_sum};
char *message = NULL;

int main(int ac, char **av)
{
    ac == 1 ? print_error("Usage : ./ft_ssl md5|sha256 [-pqrs] [FILE]\n") : 0;
    if (check_current_machine_endianess() == BENDIAN)
        print_error("This program must be run on a LITTLE ENDIAN system. Wait the PRO version for BIG ENDIAN.\n");
    //NE PAS OUBLIER DE CHANGER CA CAR A LA FIN CE SERA UN FICHIER ou STDIN
    h_functions[p_info.hash_mode]((uint8_t *)av[2], ft_strlen(av[2]));
    return 0;
}
