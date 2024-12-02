#include <cstdio>

const int n=5, m=5;

void print_indices(float arr1[], int arr2[])
{
    for(int i=0; i<m; i++)
    {
        if(arr2[i] > n)
            printf("[%d]=NAN, ", arr2[i]);
        else
            printf("[%d]=%f, ", arr2[i], arr1[arr2[i]]);
    }
}

int main()
{
    float arr1[n] = {2.3, 3.1, 0.5, 3.4, 5.2};
    int arr2[m] = {4, 1, 3, 9, 1};

    print_indices(arr1, arr2);

    return 0;
}