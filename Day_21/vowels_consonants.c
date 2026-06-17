#include <stdio.h>

int main()
{
    char st[] = "HEllo world";

    int i = 0, vowels_count = 0, consonants_count = 0, spaces = 0;
    char c = st[i];
    for (int i = 0; st[i] != '\0'; i++) {
        if (st[i] >= 'A' && st[i] <= 'Z') {
            st[i] = st[i] + 32;
        }
    }
    while (c != '\0')
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowels_count++;
        else if (c==' ')
            spaces++;
        else
            consonants_count++;
        i++;
        c = st[i];
    }
    printf("Total vowels in string '%s' is %d\n", st, vowels_count);
    printf("Total consonants in string '%s' is %d", st, consonants_count);
    return 0;
}