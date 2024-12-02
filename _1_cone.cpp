#include <cstdio>

int cone_volume(int radius, int height)
{
    return ((3.14*(radius*radius)*height)/3);
}

int main()
{
    int r, h, v;
    scanf("%d\n%d", &r, &h);
    if(r<0 || h<0)
        printf("Bledne dane\n");
    else
    {
        v = cone_volume(r, h);
        printf("%d", v);
    }


    return 0;
}
