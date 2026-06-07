#include <stdio.h>

int main()
{
    int n;
    printf("enter the number of rows: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        char ch = 'A';
        for (int j = 1; j <= i; j++)
        {
            printf("%c", ch);
            ch += 1;
        }
        
        char chr = 'A' + i - 2;
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%c", chr);
            chr -= 1;
        }

        printf("\n");
    }
    return 0;
}