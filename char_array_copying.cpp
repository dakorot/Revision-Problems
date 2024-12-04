#include <cstdio>

const int size = 101;


void copy_string(char src[], char dst[])
{
    for(int i=0; src[i]; i++)
    {
        dst[i] = src[i];
    }
}

void print_char_array(char src[])
{
    for(int i=0; src[i]; i++)
        printf("%c", src[i]);
}

int main()
{
    char arr1[size] = {0}, arr2[size] = {0};
    scanf("%100[^\n]", arr1);
    copy_string(arr1, arr2);
    print_char_array(arr2);
    return 0;
}