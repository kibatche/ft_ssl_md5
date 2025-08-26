#include "ft_ssl.h"

// https://en.wikipedia.org/wiki/Circular_shift
uint32_t rotate_left(uint32_t val, uint32_t count)
{
    const uint32_t mask = CHAR_BIT * sizeof(val) - 1;
    count = count & mask; // I prefer this 'cause i do not know much about bitwise op and it's clearer for me
    return ((val << count) | (val >> (-count & mask)));
}

uint32_t rotate_right(uint32_t val, uint32_t count)
{
    const uint32_t mask = CHAR_BIT * sizeof(val) - 1;
    count = count & mask;
    return ((val >> count) | (val << (-count & mask)));
}