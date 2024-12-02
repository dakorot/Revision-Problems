#include <cstdio>
#include <cstdlib>
#include <ctime>


int random_letter()
{
    int uppercase = 'A' + (rand()%('Z'-'A'+1));
    int lowercase = 'a' + (rand()%('z'-'a'+1));
    int chance = rand()%2;

    if(chance)
        return uppercase;
    else
        return lowercase;
}

void generate_sentence(int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<m; k++)
        {
            printf("%c", random_letter());
        }
        printf(" ");
    }
}

int main()
{
    int n = 4, m = 6;
    std::srand(std::time(0));
    generate_sentence(n, m);
}