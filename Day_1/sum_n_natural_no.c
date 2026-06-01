#include <stdio.h>
int main()
{
    int n, sum = 0, i = 1;
    printf("Enter the number up to which you want sum: ");
    scanf("%d", &n);
    while (i <= n)
    {
        sum = sum + i;
        i = i + 1;
    }
    printf("Sum of first %d natural numbers = %d", n, sum);
    return 0;
}