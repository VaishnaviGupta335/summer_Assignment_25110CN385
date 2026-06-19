#include <stdio.h>
#include <string.h>

int main()
{
    char st[] = "Hello world";
    int n = strlen(st);

    // To find maximum frequency
    int maxFreq = 0;
    for (int i = 0; i < n; i++)
    {

        if (st[i] == ' ')
            continue;

        int frequency = 0;
        for (int j = 0; j < n; j++)
        {
            if (st[i] == st[j])
            {
                frequency += 1;
            }
        }

        if (frequency > maxFreq)
        {
            maxFreq = frequency;
        }
    }

    // TO print elemnts having maximum frequency
    printf("Characters with maximum frequency are\n");
    for (int i = 0; i < n; i++)
    {
        if (st[i] == ' ')
            continue;

        int alreadyPrinted = 0;

        for (int k = 0; k < i; k++)
        {
            if (st[i] == st[k])
            {
                alreadyPrinted = 1;
                break;
            }
        }

        if (alreadyPrinted)
            continue;

        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (st[i] == st[j])
            {
                count++;
            }
        }

        if (count == maxFreq)
        {
            printf("%c ", st[i]);
        }
    }
    printf("\nFrequency:- %d", maxFreq);
    return 0;
}