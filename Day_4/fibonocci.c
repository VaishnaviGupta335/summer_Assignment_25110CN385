#include <stdio.h>
int main()
{
    int n, previousFisrt = 1, previousSecond = 0, current,i=3;
    printf("Enter the no. of terms: ");
    scanf("%d", &n);
    printf("Fibonocci series upto %d terms\n", n);
    if (n == 1)
        printf("%d", previousSecond);
    else if (n == 2)
        printf("%d %d", previousSecond, previousFisrt);
    else
    {
        printf("%d %d ", previousSecond, previousFisrt);
        while (i <= n)
        {
            current = previousFisrt + previousSecond;
            previousSecond = previousFisrt;
            previousFisrt = current;
            printf("%d ", current);
            i=i+1;
        }
    }
    return 0;
}