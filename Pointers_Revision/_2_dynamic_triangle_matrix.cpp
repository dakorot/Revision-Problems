#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>

void fill_dynamic_triangle_array_randomly(void** arr, int size)
{
    int** rows = (int**) arr;
    for(int row=0; row<size; ++row)
    {
        for(int col=0; col<size-row; ++col)
        {
            rows[row][col] = std::rand()%100;
        }
    }
}

void print_dynamic_triangle_array(int** arr, int size)
{
    int** rows = (int**)arr;
    for(int k=0; k<size; ++k)
    {
        for (int i = 0; i < size-k; ++i)
        {
            printf("%d ", rows[k][i]);
        }
        printf("\n");
    }
}

void* get_element_from_triangle_array(void** arr, int arr_size, int sizen, int x, int y)
{
    int** p_arr = (int**)arr;
    if(x<0 || x>=arr_size || y<0 || y>=arr_size)
        return nullptr;
    else
        return (void*)((*(p_arr+y)) + x);
}

int main()
{
    std::srand(std::time(nullptr));
    int N = 5;

    int** rows = new int*[N];
    for(int i=0; i<N; ++i)
        rows[i] = new int[N-i];

    fill_dynamic_triangle_array_randomly((void**)rows, N);
    print_dynamic_triangle_array(rows, N);

    int* p_element = (int*)(get_element_from_triangle_array((void**)rows, N, sizeof((*(*rows))), 0, 4));
    if(p_element == nullptr)
        printf("element not found!\n");
    else
        printf("found element: %d\n", *p_element);

    for(int i=0; i<N; ++i)
    {
        delete[] rows[i];
    }
    delete[] rows;

    return 0;
}