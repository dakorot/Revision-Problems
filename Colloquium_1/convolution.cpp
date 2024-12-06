#include <cstdio>

void conv(float f[], float g[], float c[], int m)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if((i-j)>= 0 && (i-j) <= m-1)
                c[i] += f[j]*g[i-j];
            else
                c[i] += f[j]*0.0f;
        }
    }
}

void print_float_array(float src[], int size)
{
    for(int i=0; i<size; i++)
        printf("%.1f ", src[i]);
}

int main()
{
    const int size = 4;
    float f[size] = {2.0, 4.0, 1.0, -3.0}, g[size] = {-4.0, 3.0, -1.0, 2.0}, c[size] = {0};
    conv(f, g, c, size);
    print_float_array(c, size);

    return 0;
}