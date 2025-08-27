#include "ft_ssl.h"

int check_current_machine_endianess()
{
    int i = 1;
    char *p = (char *)&i;

    if (p[0] == 1)
        return LENDIAN;
    else
        return BENDIAN;
}