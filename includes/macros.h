#ifndef MACROS_H
# define MACROS_H

# define REEF(X) if (X) free(X); X = NULL;

//to avoid undefined behavior if count == 0 || count == sizeof(VAL)
# define MASK(X) CHAR_BIT * sizeof(X) - 1

//shifting
# define SHFTL(VAL, COUNT) (VAL << (COUNT & MASK(VAL)))
# define SHFTR(VAL, COUNT) (VAL >> (COUNT & MASK(VAL)))

// https://en.wikipedia.org/wiki/Circular_shift
// rotate left 
// rotate right
# define ROTL(VAL, COUNT) (SHFTL(VAL, COUNT) | (VAL >> (-(COUNT & MASK(VAL)) & MASK(VAL))))
# define ROTR(VAL, COUNT) (SHFTR(VAL, COUNT) | (VAL << (-(COUNT & MASK(VAL)) & MASK(VAL)))) 

//md5
# define F(B, C, D) ((B & C) | ((~B) & D))
# define G(B, C, D) ((B & D) | (C & (~D)))
# define H(B, C, D) (B ^ C ^ D)
# define I(B, C, D) (C ^ (B | (~D)))

# define ROUND_1 1
# define ROUND_2 2
# define ROUND_3 3
# define ROUND_4 4

//sha256
# define CH(X, Y, Z) ((X & Y) ^ ((~X) & Z))
# define MAJ(X, Y, Z) ((X & Y) ^ (X & Z) ^ (Y & Z))
// BIG SIGMA 0 and 1 (see spec)
# define S0(VAL) (ROTR(VAL, 2) ^ ROTR(VAL, 13) ^ ROTR(VAL, 22))
# define S1(VAL) (ROTR(VAL, 6) ^ ROTR(VAL, 11) ^ ROTR(VAL, 25))
// little sigma 0 and 1 (see spec)
# define s0(VAL) (ROTR(VAL, 7) ^ ROTR(VAL, 18) ^ SHFTR(VAL, 3))
# define s1(VAL) (ROTR(VAL, 17) ^ ROTR(VAL, 19) ^ SHFTR(VAL, 10))

#endif