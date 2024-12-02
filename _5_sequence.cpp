#include <cstdio>
#include <cmath>

const int size = 19;

void fill_array(float arr[], int arr_size)
{
    for(int i=0; i<arr_size; i++)
    {
        scanf("%f", &arr[i]);
    }
}

void print_sequence(float arr[], int arr_size)
{
    float F_previous = 0, F_current = 0;
    if(arr_size == 0)
    {
        printf("%f", 0.0);
    }
    else
    {
        for(int i=0; i<arr_size; i++)
        {
            F_current = pow(-1, i+1) * arr[i] + F_previous;
            printf("%f, ", F_current);
            F_previous = F_current;
        }
    }
}

int main()
{
    float arr[size];
    int n;
    scanf("%d", &n);
    fill_array(arr, n);
    print_sequence(arr, n);

    return 0;
}
