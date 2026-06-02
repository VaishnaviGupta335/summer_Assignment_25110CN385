#include <stdio.h>
int main()
{
    int n, i = 1, fact = 1;
    printf("Enter the number: ");
    scanf("%d", &n);
    while (i <= n)
    {
        fact = fact * i;
        i = i + 1;
    }
    printf("Factorial of %d is %d", n, fact);
    return 0;
}