#include <iostream>
#include <cmath>

const int size = 6;

bool floats_are_equal(float a, float b)
{
    float epsilon = 0.00001f;
    return abs(a-b) < epsilon;
}

float vector_length(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2) + pow((z1-z2), 2));
}

int closest_transmitter(int n, float x[], float y[], float z[], float r, float x_r, float y_r, float z_r)
{
    int min_index = 0, i;
    float min_distance = vector_length(x[0], y[0], z[0], x_r, y_r, z_r);

    for(i=0; i<n; i++)
    {
        float distance = vector_length(x[i], y[i], z[i], x_r, y_r, z_r);
        std::cout << distance << std::endl;

        if((distance < r) || floats_are_equal(distance, r))
        {
            if(distance < min_distance)
            {
                min_distance = distance;
                min_index = i;
            }
        }
    }

    return min_index;
}

float vector_length(float x, float y, float z)
{
    return sqrt(pow(x,2) + pow(y,2) + pow(z, 2));
}

int main()
{
    int n=6;
    float x[size] = {2,2, 3, 5, 6, 8}, y[size] = {2, 6, 3, 7, 1, 6}, z[size] = {2, 1, 1.5, 2, 2, 2};
    float r = 2.5f, x_r = 7.0f, y_r = 2.0f, z_r = 0.0f;

    int index = closest_transmitter(n, x, y, z, r, x_r, y_r, z_r);
    std::cout << index << std::endl;

    return 0;
}
