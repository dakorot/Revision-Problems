#include <cstdio>
#include <cstring>
#include <cstdlib>

struct City {
    char name[51] = {};
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
    FILE* cities_file = fopen("/home/daria/CLionProjects/Revision-Problems/Structures_and_Files_Revision/cities.csv", "r");
    City* cities_list = new City[size];
    char buffer[256] = {};
    if(cities_file)
    {
        while(fgets(buffer, sizeof(buffer), cities_file) && (row-2 < size))
        {
//            printf("buffer: %s\n", buffer);
            ++row;
            if(row == 1) continue;

            char *name = new char[51];
            unsigned int citizens = 0;
            double x = 0.0, y = 0.0;

            char* token = std::strtok(buffer, ",");
            while(token)
            {
                std::strcpy(name, token);
                unsigned int name_len = std::strlen(token);
                name[name_len+1] = 0;

                token = std::strtok(nullptr, ",");
                citizens = std::strtoul(token, nullptr, 10);

                token = std::strtok(nullptr, ",");
                x = std::strtod(token, nullptr);

                token = std::strtok(nullptr, ",");
                y = std::strtod(token, nullptr);

                cities_list[row-2] = init_city(name, citizens, x, y);
            }
        delete[] name;
        }
    }
    print_cities_info(cities_list, size);
    fclose(cities_file);

    delete[] cities_list;
    return 0;
}
