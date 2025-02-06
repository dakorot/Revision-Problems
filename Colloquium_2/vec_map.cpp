#include <cmath>
#include <cstdio>

struct vector_2d {
    float x1, x2;
};

float vector_3d_length(float x, float y, float z)
{
    return sqrtf(x*x + y*y + z*z);
}

vector_2d project(float x, float y, float z)
{
    vector_2d v;
    float _x = x / fabs(x/vector_3d_length(x, y, z));
    float _y = y / fabs(y/vector_3d_length(x, y, z));
    v.x1 = _x;
    v.x2 = _y;

    return v;
}

void print_vec2d(vector_2d src)
{
    printf("%.2f %.2f\n", src.x1, src.x2);
}

void vec_map(float* first, float* last, float* first_2d, vector_2d (*get_2d_vector)(float, float, float))
{
    vector_2d temp;
    float* p_first = first;
    float* p_first_2d = first_2d;

    for(int i=0; p_first!=last-4; ++i)
    {
        temp = get_2d_vector(   *(p_first+i*3),
                                *(p_first+(i*3+1)),
                                *(p_first+(i*3+2))
        );
        print_vec2d(temp);
        *(p_first_2d+i*2) = temp.x1;
        *(p_first_2d+i*2+1) = temp.x2;

        ++p_first;

    }
}

void fill_vectors_3d(float src[], float* dst, int size)
{
    for(int i=0; i<size; ++i)
        dst[i] = src[i];
}

void print_vectors_2d(float* src, int size)
{
    for(int i=0; i<size; ++i)
        printf("%.2f ", *src++);
}

int main()
{
    int size_2d = 8, size_3d = 12;
    float* vectors_2d = new float[size_2d];
    float* vectors_3d = new float[size_3d];

    float values_3d[size_3d] = {    2.0, 4.0, 1.0,
                                    -2.0, 7.0, 3.0,
                                    -3.0, 1.0, -3.0,
                                    5.0, -5.0, 1.0
    };

    fill_vectors_3d(values_3d, vectors_3d, size_3d);
    // printf("%.2f", vectors_3d[0]);
    vec_map(vectors_3d, vectors_3d+size_3d, vectors_2d, project);
    print_vectors_2d(vectors_2d, size_2d);



    delete[] vectors_2d;
    delete[] vectors_3d;

    return 0;
}