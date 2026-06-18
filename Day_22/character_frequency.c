#include <stdio.h>

int main()
{
    char st[] = "Hello World";
    
    char character;
    printf("Enter the character to check frequency: ");
    scanf("%c", &character);

    int freq = 0;
    for (int i = 0; st[i] != '\0'; i++)
    {
        if (st[i] == character)
            freq++;
    }

    printf("Frequency of character %c is %d", character, freq);
    return 0;
}