#include <cstdio>

void dyadic_3x3(float a[], float b[], float res[])
{
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            res[row*3 + col] = a[row] * b[col];
        }
    }
}

/*
 * res[0] = a[0]*b[0];
 * res[1] = a[0]*b[1];
 * res[2] = a[0]*b[2];
 *
 * res[3] = a[1]*b[0];
 * res[4] = a[1]*b[1];
 * res[5] = a[1]*b[2];
 *
 * res[6] = a[2]*b[0];
 * res[7] = a[2]*b[1];
 * res[8] = a[2]*b[2];
 *
 * */

void print_matrix_3x3(float arr[])
{
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            printf("%f ", arr[row*3 + col]);
        }
        printf("\n");
    }
}

int main()
{
    float a[3] = {1, 2, 3}, b[3] = {4, 5, 6}, res[9] = {0};
    dyadic_3x3(a, b, res);
    print_matrix_3x3(res);

    return 0;
}