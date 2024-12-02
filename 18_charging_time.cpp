#include <cstdio>
#include <cstdlib>

bool floats_are_equal(float a, float b)
{
    float epsilon = 0.01f;
    return std::abs(a-b) < epsilon;
}
/*Jako prosta spadająca:
 * efficiency(capacity) = a*capacity + b, gdzie b = 0.5f*max_charge_efficiency i capacity = current_capacity;
 * a - ?
 * 1) current_capacity/max_capacity = current_capacity_percentage
 * 2) 1 - current_capacity/max_capacity = capacity_to_charge_percentage
 * 3) current_efficiency = capacity_to_charge_percentage * 0.5f*max_charge_efficiency
 * 4) current_capacity = current_efficiency + 0.5f*max_charge_efficiency
 * */

float charging_time(float max_capacity, float capacity, float max_charge_efficiency)
{
    float current_capacity = capacity, current_efficiency_percentage;
    int time = 0;

    printf("%d %.2f\n", time, current_capacity);

    while(!floats_are_equal(current_capacity, max_capacity))
    {
        current_efficiency_percentage = (1 - current_capacity/max_capacity)*0.5f*max_charge_efficiency + 0.5f*max_charge_efficiency;
        current_capacity += current_efficiency_percentage;

        if(current_capacity > max_capacity)
        {
            current_capacity = max_capacity;
            ++time;
        }

        printf("%d %.2f\n", time, current_capacity);
        ++time;
    }

    return time;
}

int main()
{
    float max_capacity=240.0f, capacity=112.5f, max_charge_efficiency=15.0f;
    float time = charging_time(max_capacity, capacity, max_charge_efficiency);

    return 0;
}