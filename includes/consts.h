#ifndef CONSTS_H
# define CONSTS_H

# define REEF(x) if (x) free(x); x = NULL;

# define F(B, C, D) ((B & C) | ((~B) & D))
# define G(B, C, D) ((B & D) | (C & (~D)))
# define H(B, C, D) (B ^ C ^ D)
# define I(B, C, D) (C ^ (B | (~D)))

# define ROUND_1 1
# define ROUND_2 2
# define ROUND_3 3
# define ROUND_4 4

#endif