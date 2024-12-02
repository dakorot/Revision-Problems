#include <iostream>
#include <cstdio>

const int size = 10;

int is_numbers(char src[])
{
    int num = 0;

    for(int i=0; i<size-1; i++)
    {
        if(src[i]>='0' && src[i]<='9')
        {
            num = num*10 + (src[i]-'0');
        }
        else
            return -1;
    }
    return num;
}

void input_string(char src[])
{
    int i;

    for(i=0; i<size-1; i++)
    {
        std::cin >> src[i];
    }
    src[size-1] = '\0';
}

void print_char_arr(char src[])
{
    for(int i=0; i<size-1; i++)
        printf("%c ", src[i]);
}

int main()
{
    char c_string[size] = {0};

    input_string(c_string);
    int result = is_numbers(c_string);
    printf("%d\n", result);

    return 0;
}