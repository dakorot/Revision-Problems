#include <cstdio>

const int size = 101;

bool is_vowel(char letter)
{
    char vowels[6] = {'a', 'e', 'i', 'y', 'o', 'u'};

    for(int i=0; i<6; i++)
    {
        if(letter == vowels[i])
            return true;
        else
            continue;
    }

    return false;
}

void word2syllables(char word[])
{
    for(int i=0; word[i]; i++)
    {
        printf("%c", word[i]);
        if(is_vowel(word[i]) && !((word[i+1] == '\0') || (word[i+2] == '\0')))
            printf(" ");
    }
}

int main()
{
    char str[size] = {0};
    scanf("%100s", str);
    word2syllables(str);

    return 0;
}