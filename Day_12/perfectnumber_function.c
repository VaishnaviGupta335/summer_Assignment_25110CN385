#include <stdio.h>

int perfect_number(int);

int perfect_number(int x)
{
     int factorSum = 0;

    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
            factorSum += i;
    }
    
    return (factorSum == x);
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (perfect_number(n))
        printf("%d is a perfect number", n);
    else
        printf("%d is not a perfect number", n);
    return 0;
}