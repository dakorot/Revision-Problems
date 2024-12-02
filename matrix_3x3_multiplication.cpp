#include <cstdio>

void mat_mul_3x3(float* a, float* b, float* res)
{
    for(int row=0; row<3; row++) {
        for (int col = 0; col < 3; col++) {
            for (int i = 0; i < 3; i++) {
                *(res + row * 3 + col) += *(a + row * 3 + i) * *(b + i * 3 + col);
            }
        }
    }
}
/*
 * How to get a specific el. of res?
 * res = row * num_of_cols + col;
 *
 * res[0= 0*3 + 0] = a[0]*b[0] + a[1]*b[1] + a[2]*b[2] <-> res[row*3 + col] = a[col*3]*b[row*3] + a[col*3+1]*b[row*3+1] + a[col*3+2]*b[row*3+2]
 * res[1= 0*3 + 1] = a[0]*b[3] + a[1]*b[4] + a[2]*b[5]
 * res[2= 0*3 + 2] = a[0]*b[6] + a[1]*b[7] + a[2]*b[8]
 *
 * res[3= 1*3 + 0] = a[3]*b[0] + a[4]*b[1] + a[5]*b[2]
 * res[4= 1*3 + 1] = a[3]*b[3] + a[4]*b[4] + a[5]*b[5]
 * res[5= 1*3 + 2] = a[3]*b[6] + a[4]*b[7] + a[5]*b[8]
 *
 * res[6= 2*3 + 0] = a[6]*b[0] + a[7]*b[1] + a[8]*b[2]
 * res[7= 2*3 + 1] = a[6]*b[3] + a[7]*b[4] + a[8]*b[5]
 * res[8= 2*3 + 2] = a[6]*b[6] + a[7]*b[7] + a[8]*b[8]
 * */

void prints_matrix_3x3(float* matrix)
{
    for(int i=0; i<3; i++)
    {
        for(int k=0; k<3; k++)
        {
            printf("%f ", * matrix++);
        }
        printf("\n");
    }
}

int main()
{
    float a[9] = {1, 2, 3,
                  4, 5, 6,
                  7, 8, 9};

    float b[9] = {10, 11, 12,
                  13, 14, 15,
                  16, 17, 18};

    float res[9] = {0};

    mat_mul_3x3(a, b, res);
    prints_matrix_3x3(res);

    return 0;
}
