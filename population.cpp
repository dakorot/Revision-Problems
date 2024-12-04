/*
 * 0 wiosna: każda para ma jedno młode
 * 1 lato: żadnych zmian w populacji
 * 2 jesień: -10 najsłabszych
 * 3 zima: 40% ginie (po zimie zostaje 60% populacji)
 * start_population odczytano w roku 0 na początku wiosny
 * */

#include <cstdio>
#include <cmath>

int population_counter(int population, int year, int season)
{
    if(population < 0)
        population = 0;
    if(year==0 || population==0)
        return floor(population);

    switch(season)
    {
        case 0:
        {
            return population_counter(floor(population+population/2), year-1, (season+1)%4);
        }
        case 1:
        {
            return population_counter(floor(population), year-1, (season+1)%4);
        }
        case 2:
        {
            return population_counter(floor(population-10), year-1, (season+1)%4);
        }
        case 3:
        {
            return population_counter(floor(population-0.4*population), year-1, (season+1)%4);
        }
        default:
        {
            return floor(population);
        }
    }
}

int main()
{
    int people = population_counter(50, 5, 2);
    printf("%d\n", people);

    return 0;
}