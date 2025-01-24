#include <cstdio>
#include <cstdlib>
#include <ctime>

void scal_numbers(int** src, float** dst, int rows, int cols)
{
    for(int i=0; i<rows; ++i)
    {
        for (int k=0; k<cols; ++k)
        {
            dst[i][k] = src[i][2*k]*1.0f + src[i][2*k+1]*0.1f;
        }
    }
}

void fill_dynamic_array_randomly(int** src, int rows, int cols)
{
    for(int i=0; i<rows; ++i)
    {
        for(int k=0; k<2*cols; ++k)
        {
            src[i][k] = std::rand()%10;
        }
    }
}

void print_int_dynamic_array(int** src, int rows, int cols)
{
    for(int i=0; i<rows; ++i)
    {
        for(int k=0; k<2*cols; ++k)
        {
            printf("%d ", src[i][k]);
        }
        printf("\n");
    }
}

void print_float_dynamic_array(float** src, int rows, int cols)
{
    for(int i=0; i<rows; ++i)
    {
        for(int k=0; k<cols; ++k)
        {
            printf("%.2f ", src[i][k]);
        }
        printf("\n");
    }
}

int main()
{
    std::srand(std::time(nullptr));
    int n, m;
    scanf("%d %d", &n, &m);
    int** arr2d = new int*[n];
    for(int i=0; i<n; ++i)
        arr2d[i] = new int[2*m];

    fill_dynamic_array_randomly(arr2d, n, m);
    print_int_dynamic_array(arr2d, n, m);

    float** arr2d_2 = new float*[n];
    for(int i=0; i<n; ++i)
        arr2d_2[i] = new float[m];

    scal_numbers(arr2d, arr2d_2, n, m);
    print_float_dynamic_array(arr2d_2, n, m);

    for(int i=0; i<n; ++i)
    {
        delete[] arr2d[i];
        delete[] arr2d_2[i];
    }
    delete[] arr2d;
    delete[] arr2d_2;

    return 0;
}