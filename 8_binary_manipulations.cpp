#include <cstdio>
#include <iostream>

int binary_manipulations(unsigned char a, unsigned char b)
{
    int younger_bits_mask = 0b00001111;
    int new_older, new_younger;

    new_older = (b & younger_bits_mask) << 4;
    new_younger = b >> 4;
    b = new_older | new_younger;

    int a_remainder = a%8;

    int bit_negation_mask = 1 << a_remainder;
    b = b ^ bit_negation_mask;

    return b;
}

int main()
{
    unsigned char t, s;
    scanf("%hhu\n%hhu", &t, &s);

    int res = binary_manipulations(t, s);
    printf("%b = %d\n", res, res);

    return 0;
}