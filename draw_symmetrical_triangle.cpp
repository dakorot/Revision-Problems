#include <cstdio>

void draw_symmetrical_triangle(int n)
{
    for(int i=0; i<=n; i++)
    {
        for(int k=1; k<=n-i; k++)
            printf(" ");

        for(int k=1; k<=((2*i)-1); k++)
            printf("*");

        printf("\n");
    }
}

int main()
{
    draw_symmetrical_triangle(20);

    return 0;
}