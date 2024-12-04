#include <cstdio>

float e_to_x(float x)
{
    float e = 1.0;
    float px = 1.0;
    float fi = 1.0;

    for(int i=0; i<20; i++)
    {
        //e += x^i / (i!);
        px *= x;
        fi = fi * i;
        e += px / fi;

        return e;
    }
}

int find_min_index(int arr[], int n, int start_idx)
{
    int idx_min = start_idx;

    for(int i=start_idx+1; i<n; i++)
    {
        if(arr[i] < arr[idx_min])
            idx_min = i;
    }

    return idx_min;
}

void swap(int&a, int& b)
{
    int _a = a;
    a = b;
    b = _a;
}

void selection_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int idx = find_min_index(arr, n, i);
        swap(arr[idx], arr[i]);
    }
}

void bubble_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int k=0; k<n-1; k++)
        {
            if(arr[k] > arr[k+1])
                swap(arr[k], arr[k+1]);
        }
    }
}

void print_array(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
}

bool is_digit(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}

int copy_only_ascii_digits(const char src[], char dst[], int n)
{
    int len = 0;

    for(int i=0; i<n; i++)
    {
        if(is_digit(src[i]))
        {
            dst[len] = src[i];
            len++;
        }
    }

    return len;
}

void convert_ascii_digits_to_numbers(char arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = arr[i] - '0';
    }
}

int find_min_index_bits(int arr[], int n, int start_idx)
{
    int idx_min = start_idx;

    for(int i=start_idx+1; i<n; i++)
    {
        if(arr[i] < arr[idx_min])
            idx_min = i;
    }

    return idx_min;
}

int bits_count(char c)
{
    /*switch(c)
    {
        case 0: return 0;
        case 1:
        case 2:
        case 4:
        case 8: return 1;
        case 3:
        case 5:
        case 6:
        case 9: return 2;
        case 7: return 3;
        default: return 0;
    }*/

    int count = 0;

    for (int i=0; i<4; i++)
    {
        if(((c >> i) & 1))
            count++;
    }

    return count;
}

void sort_by_bits(char arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int idx = find_min_index_bits(arr, n, i);
        swap(arr[idx], arr[i]);
    }
}

void sort_main(char str[], int n)
{
    char digits[200] = {0};
    int n_digits = copy_only_ascii_digits(str, digits, n);
    convert_ascii_digits_to_numbers(digits, n_digits);
    sort_by_bits(digits, n_digits);
}

int main()
{
    return 0;
}