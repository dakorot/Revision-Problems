#include <cstdio>

const int SIZE = 50;

void save_if_digit(char src[], char dst[], int& counter)
{

    for(int i=0; i<SIZE; i++)
    {
        if((src[i]) >= '0' && (src[i] <= '9'))
            dst[counter++] = src[i];
    }
}

int ascii_to_int_digit(char a)
{
    return a -= '0';
}

void save_if_at_least_twice(char src[], int dst[], int src_size)
{

    for(int i=0; i<src_size; i++)
    {
        dst[ascii_to_int_digit(src[i])]++;
    }
}

void print_char_array(char arr[], int arr_size)
{
    for(int i=0; i<arr_size; i++)
        printf("%c ", arr[i]);
}

void print_int_array(int arr[], int arr_size)
{
    for(int i=0; i<arr_size; i++)
        if(arr[i] >= 2)
            printf("%d ", i);
}

int main()
{
    char c_string[SIZE] = "a4b534a1bb2c1b151a";
    char filtered_c_string[SIZE] = {0};
    int result[SIZE] = {0}, counter = 0;

    save_if_digit(c_string, filtered_c_string, counter);
    print_char_array(filtered_c_string, counter);
    save_if_at_least_twice(filtered_c_string, result, counter);
    printf("\n\n");
    print_int_array(result, counter);

    return 0;
}