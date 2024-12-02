#include <cstdio>

const int size = 12;

void uppercase_to_lowercase(char src[])
{
    for(int i=0; src[i]!='\0'; i++)
    {
        if(src[i] >= 'A' && src[i] <= 'Z')
            src[i] = src[i] - 'A' + 'a';
    }
}

void print_unsigned_int_array(unsigned int src[])
{
    for(int i=0; i<size-1; i++)
    {
        printf("%u ", src[i]);
    }
}

void count_occurrences(char src[], unsigned int occ[])
{
    for(int i=0; src[i]!='\0'; i++)
    {
        char to_remember = src[i];

        for(int k=0; src[k]!='\0'; k++)
        {
            if(src[k]==to_remember)
                occ[i]++;
        }
    }
}

int main()
{
    char str[size] = "Ala ma kota";
    unsigned int occ[size-1] = {0};
    uppercase_to_lowercase(str);
    count_occurrences(str, occ);
    print_unsigned_int_array(occ);


    return 0;
}