#include <cstdio>
#include <cstring>
#include <cstdlib>

char* expand(char* src, int old_size, int new_size)
{
   char* new_src = new char[new_size];
   std::memcpy(new_src, src, old_size);

   delete[] src;
   return new_src;
}

bool is_lowercase(char& src)
{
    return src >= 'a' && src <= 'z';
}

bool is_uppercase(char& src)
{
    return src >= 'A' && src <= 'Z';
}

void letters_to_whitespace(char* src)
{
    for (int i = 0; src[i]; ++i) {
        if (is_uppercase(src[i]) || is_lowercase(src[i]))
        {
            src[i] = ' ';
        }
    }
}

int get_float_from_string(char* src, float* dst)
{
    char* start = src, *end = nullptr;
    float value;
    letters_to_whitespace(src);
    int i=0;
    while(value = std::strtof(start, &end))
    {
        start = end;
        dst[i++] = value;
    }

    return i;
}

void print_float_array(float* src, int size)
{
    for(int i=0; i<size; ++i)
        printf("%.2f ", src[i]);
}

int main()
{
    char* cstring = new char[51]{"abAba4.5diej3.03dkskw1.1qqqq0.05jjj"};
    float* cstring_values = new float[10];
    int number_of_values = get_float_from_string(cstring, cstring_values);
    print_float_array(cstring_values, number_of_values);
    delete[] cstring_values;
    delete[] cstring;
    return 0;
}