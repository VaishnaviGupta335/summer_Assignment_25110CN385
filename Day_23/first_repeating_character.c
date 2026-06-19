#include <stdio.h>
#include <string.h>

int main()
{
    char st[] = "Hello World";

    int n = strlen(st);
    for (int i = 0; i < n; i++)
    {
        int repeating = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (st[i] == st[j])
            {
                repeating = 0;
                break;
            }
        }
        if (repeating==0)
        {
            printf("First repeating character is %c", st[i]);
            break;
        }
    }
    return 0;
}