#include <stdio.h>
int main()
{
    int n, i = 2, m, isprime,j;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Prime numbers between 1-%d are\n",n);
    while (i <= n)
    {
        j=2;
        isprime=1;
        while (j <= i / 2)
        {
            m = i % j;
            if (m == 0)
            {
                isprime = 0;
                break;
            }
            j = j + 1;
        }
        if (isprime == 1)
            printf("%d ",i);
        i = i + 1;
    }
    return 0;
}