#include <stdio.h>
int main()
{
    int firstNum, secondNum, i = 1, m, n, gcd;
    printf("Enter two number: ");
    scanf("%d %d", &firstNum, &secondNum);
    while (i <= firstNum && i <= secondNum)
    {
        m = firstNum % i;
        n = secondNum % i;
        if (m == 0 && n == 0)
        {
            gcd = i;
        }
        i = i + 1;
    }
    printf("GCD of numbers= %d", gcd);
    return 0;
}