int main()
{
    unsigned int lenBit = 1001;// 1 char == 8 bits
    unsigned int lenBitTranformed = lenBit + 1; // add 1

    while (lenBitTranformed % 512 != 448)
        lenBitTranformed += 1;
    printf("%u\n", lenBitTranformed);
}