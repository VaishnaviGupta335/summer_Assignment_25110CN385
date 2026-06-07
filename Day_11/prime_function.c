#include <stdio.h>

int prime(int);

int prime(int x)
{
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
            return 0;
    }
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    if (prime(n))
    {
        printf("%d is a prime number", n);
    }
    else
    {
        printf("%d is not a prime number", n);
    }
    return 0;
}