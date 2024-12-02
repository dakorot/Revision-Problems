#include <cstdio>

const int size = 6;

int char_to_int(char num[])
{
    int int_num = 0;

    for(int i=0; num[i]!='\0'; i++)
    {
       int_num = int_num * 10 + (num[i] - '0');
    }

    return int_num;
}

int main()
{
    char number[size] = "65536";

    printf("\n\n%d", char_to_int(number));

    return 0;
}