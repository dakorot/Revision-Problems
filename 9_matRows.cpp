#include <iostream>

int matRows(int mat[], int n, int m)
{
    int checker = 0, sorted_rows = 0;
    for(int row=0; row<n; row++)
    {
        for(int col=1; col<m; col++)
        {
            if(mat[row*m+col-1] < mat[row*m+col])
            {
                ++checker;
            }
            else
            {
                checker = 0;
                break;
            }
        }
        if (checker>0)
        {
            ++sorted_rows;
            checker = 0;
        }
    }
    return sorted_rows;
}

int main()
{
    const int n = 4, m = 4;
    int arr[n*m] = {1, 3, 4, 5,
                  5, 6, 7, 8,
                  8, 11, 35, 36,
                  1, 4, 2, 1};

    int sorted = matRows(arr, n, m);
    std::cout << sorted << std::endl;

    return 0;
}