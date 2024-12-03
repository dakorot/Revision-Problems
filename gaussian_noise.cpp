#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

float marsaglia_gaussian_noise(float sigma, float mean)
{
    static float random_value_in_queue;
    static bool value_in_queue = false;

    if(value_in_queue)
    {
        value_in_queue = false;
        return sigma * random_value_in_queue + mean;
    }

    float u, v, s;
    do {
        u = (((float)rand() / RAND_MAX)) * 2.0 - 1.0;
        v = (((float)rand() / RAND_MAX)) * 2.0 - 1.0;
        s = pow(u, 2) + pow(v, 2);
    } while (s>=1.0 || s==0.0);

    random_value_in_queue = v * s;
    value_in_queue = true;

    s = sqrt((-2.0)*log(s)/s);

    return mean + sigma * u * s;
}

int main()
{
    std::srand(std::time(0));

    for(int i=0; i<50; i++)
    {
        printf("%.2f ", marsaglia_gaussian_noise(3.0f, 4.0f));
    }

    return 0;
}