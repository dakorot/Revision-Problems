#include <cstdio>

const int size = 9;

void bin2dec(unsigned char src[], unsigned int& dst)
{
    for(int i=0; src[i]; i++)
        dst += (src[i] - '0') * (1 << (9-2-i));
}

void correct(unsigned int& src)
{
    int bit3_mask = 1<<3;
    src = src ^ bit3_mask;
    int four_younger = 0b00001111, four_older = 0b11110000;
    src = ((src & four_younger) << 4) | ((src & four_older) >> 4);
}

int main()
{
    unsigned char binary[size] = {0};
    unsigned int decimal = 0;
    scanf("%100s", binary);

    bin2dec(binary, decimal);
    correct(decimal);
    printf("%u\n", decimal);

    return 0;
}


