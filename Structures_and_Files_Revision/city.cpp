#include <cstdio>
#include <cstring>
#include <cstdlib>

struct City {
    char name[51];
    unsigned int citizens_number;
    double x, y;
};

City init_city(char* name, unsigned int citizens, double x, double y)
{
    City new_city;

    std::strcpy(new_city.name, name);
    new_city.citizens_number = citizens;
    new_city.x = x;
    new_city.y = y;

    return new_city;
}

void print_cities_info(City* src, int size)
{
    for(int i=0; i<size; ++i)
    {
        printf("%s\t%d\t%f\t%f\n", src[i].name, src[i].citizens_number, src[i].x, src[i].y);
    }
}

int main()
{
    unsigned int size = 3, cols = 4, row = 0;
    FILE* cities_file = fopen("cities.csv", "r");
    City* cities_list = new City[size];
    char buffer[256] = {};
    if(cities_file)
    {
        while(fgets(buffer, sizeof(buffer), cities_file) && (row < size))
        {
            printf("buffer: %s\n", buffer);
            ++row;
            if(row == 1) continue;

            char name[51] = {};
            unsigned int citizens = 0;
            double x = 0.0, y = 0.0;

            char* comma = std::strchr(buffer, ',');

            std::strncpy(name, buffer, comma-buffer);
            unsigned int len_of_rest = std::strlen(comma);
            char* temp = new char[len_of_rest];
            std::strcpy(temp, comma);

            comma = temp-1;
            while(comma = strchr(comma+1, ',')) { *comma = ' '; }

            citizens = std::strtoul(temp, &comma, 10);
            x = std::strtod(comma, &comma);
            y = std::strtod(comma, nullptr);
            cities_list[row-1] = init_city(name, citizens, x, y);

            delete[] temp;
        }
    }
    print_cities_info(cities_list, 3);
    fclose(cities_file);

    delete[] cities_list;
    return 0;
}