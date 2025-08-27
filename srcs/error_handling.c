#include "ft_ssl.h"

void print_error(char *error_message)
{
    write(2, error_message, ft_strlen(error_message));
    exit(1);
}