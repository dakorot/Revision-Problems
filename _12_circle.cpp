#include <iostream>
#include <cmath>

void draw_circle(int r)
{
    for(int y=-r; y<=r; y++)
    {
        for(int x=-r; x<=r; x++)
        {
            if(sqrt(x*x + y*y) <= r)
                std::cout << '#';
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    int r;
    std::cin >> r;
    if(r>0)
        draw_circle(r);
}
