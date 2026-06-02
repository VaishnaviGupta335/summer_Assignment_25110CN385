#include <stdio.h>
int main()
{
    int n, rem, i, isStrong = 0, fact, temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (n > 0)
    {
        fact = 1;
        i = 1;
        rem = n % 10;
        while (i <= rem)
        {
            fact = fact * i;
            i = i + 1;
        }
        isStrong = isStrong + fact;
        n = n / 10;
    }
    if (isStrong == temp)
        printf("%d is a strong number", temp);
    else
        printf("%d is not a strong number", temp);
    return 0;
}