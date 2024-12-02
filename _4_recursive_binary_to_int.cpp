#include <cstdio>

const int size = 9;

int binary_to_decimal(char bin[], int index, int bin_size)
{
    if(index == bin_size)
        return 0;

    int decimal_value = (bin[index] - '0') * (1 << (bin_size-1 - index));

    return decimal_value + binary_to_decimal(bin, ++index, bin_size);
}

/*
 * 10010011
 * 1*2^7 + 0*2^6 + 0*2^5 + 1*2^4 + 0*2^3 + 0*2^2 + 1*2^1 + 1*2^0
 * */

int main()
{
    char bin_num[size] = "10010011";

    int decimal = binary_to_decimal(bin_num, 0, size-1);
    printf("\n%d\n", decimal);

    return 0;
}
