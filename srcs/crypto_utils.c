#include "ft_ssl.h"

extern HASH_MODE HMODE;

/**
 * @brief This function pad a message. First we compute the length of the padding
 * This length must resolve the following function : l + 1 + k ≡ 448 mod 512, where l is the original
 * length of the message, and k the length of the padding.
 * 
 * This padding start with the bit '1' and the other bits are '0'. k is represented as an array, P[64].
 * 
 * For further information, please see section 5.1.1 NIST.FIPS.180-4.pdf. SHA256 and md5 share the same method for padding.
 * 
 * @param message // the original message
 * @param len // the original length of the message
 * @param final_len_byte  // the final length of the padded message
 * @return uint8_t* // the type of the padded message (unsigned char*)
 */
uint8_t *pad_message(uint8_t *message, int len, int *final_len_byte)
{
    //P is what we add after the message. It will never have more than 64 values
    // uint8_t, see rfc for md5
    const uint8_t P[64] = {
        128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    uint32_t remaining = len % 64;
    uint32_t paddingLen = 0;
    if (remaining >= 56) paddingLen = 56 - (64 - remaining);
    else paddingLen = 56 - remaining;
    *final_len_byte = len + paddingLen + 8;// len in byte not in bit
    uint8_t *padded_message = malloc(sizeof(char) * (*final_len_byte));
    if (padded_message == NULL) print_error("malloc failed.\n");
    uint64_t len64;

    if (HMODE == MD5) len64 = (uint64_t)len * 8;// stupid I am : the len MUST BE in bits not in bytes...
    else if (HMODE == SHA256) len64 = __bswap_64((uint64_t)len * 8);
    else { REEF(padded_message); print_error("Wrong hash mode.\n");}

    ft_memcpy(padded_message, message, len);
// we add the bit '1' to the message + the '0's
    ft_memcpy(padded_message + len, P, paddingLen);
// we add the original len to the msg in 64bits to have a perfect multiple of 512.
    ft_memcpy(padded_message + len + paddingLen, &len64, sizeof(uint64_t));
    return padded_message;
}

uint32_t split_chunk_into_word_little_endian(uint32_t one, uint32_t two, uint32_t three, uint32_t four)
{
    return ((four << 24) | (three << 16) | (two << 8)  | one);//little endian => https://stackoverflow.com/questions/53289526/c-convert-four-unsined-chars-to-one-unsigned-int 
}

uint32_t split_chunk_into_word_big_endian(uint32_t one, uint32_t two, uint32_t three, uint32_t four)
{
    return ((one << 24) | (two << 16) | (three << 8)  | four);//big endian => https://stackoverflow.com/questions/53289526/c-convert-four-unsined-chars-to-one-unsigned-int 
}