#include <cstdio>

struct Hex_Crystal {
    char name[11];
    unsigned char e;
};

int decrypt_crystal_power(unsigned char e)
{
    unsigned char count = 0;

    while(e)
    {
        if((e & 1) == 0)
            ++count;

        e >>= 1;
    }

    return (count == 0) ? -1 : count;
}

Hex_Crystal* best_hex_crystal(Hex_Crystal* src, unsigned int size, int (*calculate_power)(unsigned char))
{
    int decrypted_power;
    unsigned int max_power = 0;
    Hex_Crystal* best_crystal = src;
    for(int i=0; i<size; ++i)
    {
        decrypted_power = calculate_power(src[i].e);
        if(decrypted_power < 0)
            continue;
        else if(decrypted_power > max_power)
        {
            best_crystal = &src[i];
            max_power = decrypted_power;
        }
    }
    return best_crystal;
}

int main()
{
    int N;
    scanf("%d", &N);
    Hex_Crystal* crystals = new Hex_Crystal[N];
    for(int i=0; i<N; ++i)
    {
        scanf("%hhu:%10s%*c", &crystals[i].e, crystals[i].name);
    }
    /*
     123:blue = 1111011
     111:red = 1101111
     223:purple = 11011111
     0:green = 0
     */

    Hex_Crystal* best = best_hex_crystal(crystals, N, decrypt_crystal_power);
    printf("%s\n", best->name);

    delete[] crystals;
    return 0;
}