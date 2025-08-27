#include "ft_ssl.h"

static void printReverseEndian(unsigned n) {
  printf("%02x%02x%02x%02x", n & 0xff, (n >> 8) & 0xff, (n >> 16) & 0xff, n >> 24);
}

void sha256_sum(uint8_t *message, uint32_t len)
{
    uint32_t K[64] = {
        __bswap_32(0x428a2f98), __bswap_32(0x71374491), __bswap_32(0xb5c0fbcf), __bswap_32(0xe9b5dba5), __bswap_32(0x3956c25b), __bswap_32(0x59f111f1), __bswap_32(0x923f82a4), __bswap_32(0xab1c5ed5),
        __bswap_32(0xd807aa98), __bswap_32(0x12835b01), __bswap_32(0x243185be), __bswap_32(0x550c7dc3), __bswap_32(0x72be5d74), __bswap_32(0x80deb1fe), __bswap_32(0x9bdc06a7), __bswap_32(0xc19bf174),
        __bswap_32(0xe49b69c1), __bswap_32(0xefbe4786), __bswap_32(0x0fc19dc6), __bswap_32(0x240ca1cc), __bswap_32(0x2de92c6f), __bswap_32(0x4a7484aa), __bswap_32(0x5cb0a9dc), __bswap_32(0x76f988da),
        __bswap_32(0x983e5152), __bswap_32(0xa831c66d), __bswap_32(0xb00327c8), __bswap_32(0xbf597fc7), __bswap_32(0xc6e00bf3), __bswap_32(0xd5a79147), __bswap_32(0x06ca6351), __bswap_32(0x14292967),
        __bswap_32(0x27b70a85), __bswap_32(0x2e1b2138), __bswap_32(0x4d2c6dfc), __bswap_32(0x53380d13), __bswap_32(0x650a7354), __bswap_32(0x766a0abb), __bswap_32(0x81c2c92e), __bswap_32(0x92722c85),
        __bswap_32(0xa2bfe8a1), __bswap_32(0xa81a664b), __bswap_32(0xc24b8b70), __bswap_32(0xc76c51a3), __bswap_32(0xd192e819), __bswap_32(0xd6990624), __bswap_32(0xf40e3585), __bswap_32(0x106aa070),
        __bswap_32(0x19a4c116), __bswap_32(0x1e376c08), __bswap_32(0x2748774c), __bswap_32(0x34b0bcb5), __bswap_32(0x391c0cb3), __bswap_32(0x4ed8aa4a), __bswap_32(0x5b9cca4f), __bswap_32(0x682e6ff3),
        __bswap_32(0x748f82ee), __bswap_32(0x78a5636f), __bswap_32(0x84c87814), __bswap_32(0x8cc70208), __bswap_32(0x90befffa), __bswap_32(0xa4506ceb), __bswap_32(0xbef9a3f7), __bswap_32(0xc67178f2)
    };

    uint32_t h0 = __bswap_32(0x6a09e667);
    uint32_t h1 = __bswap_32(0xbb67ae85);
    uint32_t h2 = __bswap_32(0x3c6ef372);
    uint32_t h3 = __bswap_32(0xa54ff53a);
    uint32_t h4 = __bswap_32(0x510e527f);
    uint32_t h5 = __bswap_32(0x9b05688c);
    uint32_t h6 = __bswap_32(0x1f83d9ab);
    uint32_t h7 = __bswap_32(0x5be0cd19);

    int padded_message_len = 0;
    uint8_t *padded_message = pad_message(message, len, &padded_message_len);
    chunked_message *chunked_msg_array = split_message_into_chuncks_sha256(padded_message, padded_message_len);
    int number_of_chunks = padded_message_len / 64;

    for (int n = 0; n < number_of_chunks; n++)// n is the index inside the chunked message array
    {
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;
        uint32_t f = h5;
        uint32_t g = h6;
        uint32_t h = h7;
        for (int t = 0; t < 64; t++)
        {
            uint32_t T1 = __bswap_32(h + S1(e) + CH(e, f, g) + K[t] + chunked_msg_array[n].word[t]);
            uint32_t T2 = __bswap_32(S0(a) + MAJ(a, b, c));
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }
    printReverseEndian(h0);
    printReverseEndian(h1);
    printReverseEndian(h2);
    printReverseEndian(h3);
    printReverseEndian(h4);
    printReverseEndian(h5);
    printReverseEndian(h6);
    printReverseEndian(h7);
    REEF(padded_message);
    REEF(chunked_msg_array->word);
    REEF(chunked_msg_array);
}