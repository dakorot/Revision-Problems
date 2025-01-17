#include <cstdio>

void swap(int& a, int& b)
{
    int _a = a;
    a = b;
    b = _a;
}

void sort_array(int* src, int size)
{
    for(int i=0; i<size; ++i)
    {
        for(int k=0; k<size; ++k)
        {
            if(src[k-1] > src[k])
                swap(src[k-1], src[k]);
        }
    }
}

void copy_k_biggest_values(int* src, int* dst, int k, int n)
{
    for(int i=0; i<k; ++i)
    {
        dst[i] = src[n-i-1];
    }
}

void func(const int* arr, int n, int k, int* result)
{
   int* dyn_arr = new int[n];

   for(int i=0; i<n; ++i)
       dyn_arr[i] = *(arr+i);

   sort_array(dyn_arr, n);
   copy_k_biggest_values(dyn_arr, result, k, n);

   delete[] dyn_arr;
}

void print_int_array(int src[], int size)
{
    printf("\n");
    for(int i=0; i<size; ++i)
        printf("%d ", src[i]);
}

int main()
{
    int nums[5] = {11, 13, 20, 1, 2};
    int res[5] = {0};

    func(nums, 5, 3, res);
    print_int_array(res, 3);

    return 0;
}