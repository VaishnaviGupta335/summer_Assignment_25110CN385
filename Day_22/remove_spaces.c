#include <stdio.h>
#include <string.h>

int main()
{
    char st[] = "Hello  World";

    int n = strlen(st);
    for (int i = 0; i < n; i++)
    {
        if (st[i] == ' ')
        {
            for (int j = i; j < n; j++)
            {
                st[j] = st[j + 1];
            }
            n--;
            i--;
        }
    }

    printf("%s", st);
    return 0;
}