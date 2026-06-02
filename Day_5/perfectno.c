#include <stdio.h>
int main()
{
    int n, m, i = 1, temp, isPerfect = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (i <= temp / 2)
    {
        m = temp % i;
        if (m == 0)
        {
            isPerfect = isPerfect + i;
        }
        i = i + 1;
    }
    if (isPerfect == n)
        printf("%d is a perfect number", n);
    else
        printf("%d is not a perfect number", n);
    return 0;
}