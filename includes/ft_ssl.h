#ifndef FT_SSL_H
# define  F_SSL_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "libft/libft.h"
# include "consts.h"

typedef struct t_chunked_message {
    unsigned int word[16];
}               chunked_message;

#endif