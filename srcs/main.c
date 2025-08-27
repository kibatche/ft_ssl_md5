#include "ft_ssl.h"

HASH_MODE HMODE;

static int choosen_hash_digest(char *arg)
{
    if (!ft_strcmp(arg, "md5")){
        HMODE =  MD5;
        return MD5;
    }
    else if (!ft_strcmp(arg, "sha256")){
        HMODE =  SHA256;
        return SHA256;
    }
    else
        print_error("Usage : ./ft_ssl md5|sha256 [-pqrs] [FILE]\n");
    return -1;
}

int main(int ac, char **av)
{
    ac == 1 ? print_error("Usage : ./ft_ssl md5|sha256 [-pqrs] [FILE]\n") : 0;
    if (check_current_machine_endianess() == BENDIAN)
        print_error("This program must be run on a LITTLE ENDIAN system. Wait the PRO version for BIG ENDIAN.\n");
    void (*hash_function[2])(uint8_t *, uint32_t) = {md5_sum, sha256_sum};
    //NE PAS OUBLIER DE CHANGER CA CAR A LA FIN CE SERA UN FICHIER ou STDIN
    hash_function[choosen_hash_digest(av[1])]((uint8_t *)av[2], strlen(av[2]));
    return 0;
}