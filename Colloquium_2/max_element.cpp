#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

void* max_element(void* first, int size, int element_size)
{
    if(element_size==4)
    {
        int* p_first = (int*)first;
        int* max = std::max_element(p_first, p_first+size);
        return (void*)max;
    }
    else if(element_size==1)
    {
        char* p_first = (char*)first;
        char* max = std::max_element(p_first, p_first+size);
        return (void*)max;
    }
    else if(element_size==2)
    {
        short int* p_first = (short int*)first;
        short int* max = std::max_element(p_first, p_first+size);
        return (void*)max;
    }
}

void fill_int_dynamic_array_randomly(int** src, int rows, int cols)
{
    for(int i=0; i<rows; ++i)
    {
        for(int k=0; k<cols; ++k)
            src[i][k] = 1 + 99*((std::rand())/RAND_MAX);
    }
}

void print_int_dynamic_2d_array(int** src, int rows, int cols)
{
    for(int i=0; i<rows; ++i)
    {
        for(int k=0; k<rows; ++k)
        {
            printf("%d ", src[i][k]);
        }
        printf("\n");
    }
}

void print_int_dynamic_1d_array(int* src, int size)
{
    for(int k=0; k<size; ++k)
    {
        printf("%d ", src[k]);
    }
    printf("\n");
}

void get_max_values(void* first, void* dst, int element_size, int rows, int cols)
{
    if(element_size==4)
    {
        int* p_first = (int*)first;
        int* max;
        int* p_dst = (int*)dst;
        for(int i=0; i<rows; ++i)
        {
            for(int k=0; k<cols; ++k)
            {
                max = (int*)max_element(p_first, cols, element_size);
                *p_dst++ = *max;
            }
        }
    }
    else if(element_size==2)
    {
        short int* p_first = (short int*)first;
        short int* max;
        short int* p_dst = (short int*)dst;
        for(int i=0; i<rows; ++i)
        {
            for(int k=0; k<cols; ++k)
            {
                max = (short int*)max_element(p_first, cols, element_size);
                *p_dst++ = *max;
            }
        }
    }
    else if(element_size==1)
    {
        char* p_first = (char*)first;
        char* max;
        char* p_dst = (char*)dst;
        for(int i=0; i<rows; ++i)
        {
            for(int k=0; k<cols; ++k)
            {
                max = (char*)max_element(p_first, cols, element_size);
                *p_dst++ = *max;
            }
        }
    }
}

int main()
{
    std::srand(std::time(nullptr));
    int cols = 3, rows = 3;
    int** values = new int*[rows];
    for(int i=0; i<rows; ++i)
        values[i] = new int[cols];

    int* max_values = new int[rows];


    fill_int_dynamic_array_randomly(values, rows, cols);
    // print_int_dynamic_2d_array(values, rows, cols);
    get_max_values(values, max_values, sizeof(values[0]), rows, cols);
    print_int_dynamic_1d_array(max_values, cols);

    for(int i=0; i<rows; ++i)
        delete[] values[i];
    delete[] values;
    delete[] max_values;
    return 0;
}