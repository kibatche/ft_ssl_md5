#include "ft_ssl.h"

void print_error(char *error_message)
{
    ft_putendl_fd(error_message, 2);
    exit(1);
}
