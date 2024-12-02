#include <cstdio>

const int size = 6;

int return_maximum_1_bits(int arr[])
{
    int max_num = 0, max_1_bits = 0, counter = 0;

    for(int i=0; i<size; i++)
    {
        int temp = arr[i];

        while(temp!=0)
        {
            if(temp & 1)
                ++counter;
            temp >>= 1;
        }
        if(counter >= max_1_bits)
        {
            max_1_bits = counter;
            max_num = arr[i];
        }
        counter = 0;
    }

    return max_num;
}

int main()
{
    int arr[size] = {2, 3, 4, 5, 255, 64};

    int maximum = return_maximum_1_bits(arr);
    printf("%d\n", maximum);

    return 0;
}
