#include <cstdio>
#include <algorithm>

float fun_aux(float a, float b, float c)
{
    float max = a > b ? a : b;
    max = max > c ? max : c;

    return max;
}

void fun_arr(float* src, float* dst, float (*find_max)(float, float, float), int size)
{
    for(int i=0; i<size; ++i)
    {
        dst[i] = find_max(src[3*i], src[3*i+1], src[3*i+2]);
    }
}

int main()
{
    int N = 4;
    float* source = new float[3*N];
    float* destination = new float[N];
    float values[12] = {1.0,1.0,2.5,   2.0,1.0,-0.5,   -1.5,-3.0,-4.0,   0.0,0.0,0.0};
    std::copy(values, values+12, source);

    fun_arr(source, destination, fun_aux, N);
    std::for_each(destination, destination+N, [](float value){ printf("%.2f ", value); });

    delete[] source;
    delete[] destination;
    source = nullptr;
    destination = nullptr;

    return 0;
}