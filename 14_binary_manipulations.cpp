#include <cstdio>

unsigned char younger_bits_negation(unsigned char v, int b, bool f)
{
    int mask = 0b00001111;
    v = v & mask;

    if(f)
        v = v ^ mask;

    v = v ^ (1 << b);

    return v;
}

int main()
{
    unsigned char v = 13;
    int b = 6;
    bool f = true;

    v = younger_bits_negation(v, b, f);
    printf("%d\n", v, v);

    return 0;
}