#include <stdio.h>
#include <string.h>

int main()
{
    char st[] = "Hello world";

    int n = strlen(st);
    for (int i = 0; i < n; i++)
    {
        int non_repeating = 1;
        for (int j = 0; j < n; j++)
        {
            if (st[i] == st[j] && i!=j)
            {
                non_repeating = 0;
            }
        }
        if (non_repeating)
        {
            printf("First non repeating character is %c", st[i]);
            break;
        }
    }
    return 0;
}