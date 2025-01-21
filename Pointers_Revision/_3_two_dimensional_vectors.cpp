#include <cmath>
#include <cstdio>

float get_2D_vector_length(float x, float y)
{
    return (float)sqrt((float)pow(x, 2) + (float)pow(y, 2));
}

void arr_fun(float* arr, float* last, float* res, float (*vector_length)(float, float))
{
    float* p_arr = arr;
    for(int i=0; (p_arr+i+2)!=last; ++i)
    {
        res[i] = vector_length(*(arr+2*i), *(arr+2*i+1));
    }
}

void print_float_array(float* src, int size)
{
    for(int i=0; i<size; ++i)
        printf("%.2f ", src[i]);
}

int main()
{
    const int N = 4;
    float* vectors = new float[2*N];
    float* vectors_length = new float[N];
    vectors[0] = 1.0f;
    vectors[1] = 1.0f;
    vectors[2] = 2.0f;
    vectors[3] = 1.0f;
    vectors[4] = 1.0f;
    vectors[5] = 3.0f;
    vectors[6] = 3.0f;
    vectors[7] = 1.0f;


    arr_fun(vectors, vectors+2*N, vectors_length, get_2D_vector_length);
    print_float_array(vectors_length, N);

    delete[] vectors;
    delete[] vectors_length;

    return 0;
}