#include "ft_ssl.h"

void print_error(char *errMsg)
{
    write(2, errMsg, ft_strlen(errMsg));
    exit(1);
}