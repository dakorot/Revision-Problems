#include <iostream>

int sequence(unsigned int n)
{
    if(n<2)
        return 1;
    else if(n>=2 && n<10)
        return 2 * sequence(n-1);
    else if(n>=10)
        return 3 * sequence(n-1) - sequence(n-3);
}

int main()
{
    unsigned int n1=1, n2=4, n3=10;
    std::cout << sequence(n1) << std::endl;
    std::cout << sequence(n2) << std::endl;
    std::cout << sequence(n3) << std::endl;

    return 0;
}
