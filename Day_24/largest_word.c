#include <stdio.h>
#include <string.h>

int main()
{
    char st[] = "my name is vaishnavi gupta";

    int start = 0;
    int maxStart = 0;
    int maxLen = 0;

    for (int i = 0; ; i++)
    {
        if (st[i] == ' ' || st[i] == '\0')
        {
            int len = i - start;

            if (len > maxLen)
            {
                maxLen = len;
                maxStart = start;
            }

            start = i + 1;
        }

        if (st[i] == '\0')
            break;
    }

    printf("Largest word: ");

    for (int i = maxStart; i < maxStart + maxLen; i++)
    {
        printf("%c", st[i]);
    }

    return 0;
}