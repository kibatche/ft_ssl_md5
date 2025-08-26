#include "ft_ssl.h"

int main(int ac, char **av)
{
    (void)ac;
    md5_sum((uint8_t *)av[1], ft_strlen(av[1]));//for test, we donm't need the 0 from the c language
    return 0;
}