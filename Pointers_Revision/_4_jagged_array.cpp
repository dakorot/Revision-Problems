#include <cstdio>

void fill_arr2d(float** src, int* row_lengths, int size)
{
    printf("fill your array:\n");
    for(int i=0; i<size; ++i)
    {
        for(int k=0; k<row_lengths[i]; ++k)
        {
            scanf("%f", &src[i][k]);
        }
    }
}

void sum_arr2d_rows(float** src, float* dst, int* row_lengths, int size)
{
    for(int i=0; i<size; ++i)
    {
        for(int k=0; k<row_lengths[i]; ++k)
        {
            dst[i] += src[i][k];
        }
    }
}

void print_2d_float_array(float** src, int* row_lengths, int size)
{
    for(int i=0; i<size; ++i)
    {
        for(int k=0; k<row_lengths[i]; ++k)
        {
            printf("%.2f ", src[i][k]);
        }
        printf("\n");
    }

}

void print_float_array(float* src, int size)
{
    printf("sums:\n");
    for(int i=0; i<size; ++i)
        printf("%.2f ", src[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int* arr = new int[n];

    int rows;
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &rows);

        if(rows<=0)
            return 1;
        else
            arr[i] = rows;
    }

    float** arr2d = new float*[n];
    for(int i=0; i<n; ++i)
        arr2d[i] = new float[arr[i]];

    fill_arr2d(arr2d, arr, n);
    print_2d_float_array(arr2d, arr, n);

    float* result = new float[n];
    sum_arr2d_rows(arr2d, result, arr, n);
    print_float_array(result, n);

    for(int i=0; i<n; ++i)
        delete[] arr2d[i];
    delete[] arr;
    delete[] arr2d;
    delete[] result;

    return 0;
}