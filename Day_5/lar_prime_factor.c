#include <stdio.h>
int main()
{
    int n, i = 2, j, rem, m, primeFactor, isPrime;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (i <= n)
    {
        rem = n % i;
        if (rem == 0)
        {
            j = 2;
            isPrime = 1;
            while (j <= i / 2)
            {
                m = i % j;
                if (m == 0)
                {
                    isPrime = 0;
                    break;
                }
                j = j + 1;
            }
            if (isPrime == 1)
                primeFactor = i;
        }
        i = i + 1;
    }
    printf("Largest prime factor of %d is %d", n, primeFactor);
    return 0;
}