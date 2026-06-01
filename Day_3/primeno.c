#include <stdio.h>
int main()
{
    int n, i = 2, m, isprime = 1;
    printf("Enter the number: ");
    scanf("%d", &n);
    while (i <= n / 2)
    {
        m = n % i;
        if (m == 0)
        {
            isprime = 0;
            break;
        }
        i=i+1;
    }
    if (isprime == 1)
        printf("The number is prime");
    else
        printf("Number is not prime");
    return 0;
}