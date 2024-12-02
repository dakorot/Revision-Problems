#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

float seq(unsigned int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
    {
        return (n-1)*sqrt(n-2);
    }
}

int main()
{
    std::srand(std::time(0));
    int a = std::rand()%(100+1);

    std::cout << seq(a) << std::endl;

    return 0;
}
