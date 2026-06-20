#include <stdio.h>
#include <string.h>

int main()
{
    char st[] = "Hello world";
    int n = strlen(st);

    for (int i = 0; i < n; i++)
    {
        if (st[i] == ' ')
            continue;

        int count = 1;

        while (i < n - 1 && st[i] == st[i + 1])
        {
            count++;
            i++;
        }

        printf("%c%d", st[i], count);
    }

    return 0;
}