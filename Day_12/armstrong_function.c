#include <stdio.h>
#include <math.h>

int armstrong(int);

int armstrong(int x)
{
    int count = 0, rem, sum = 0;
    int temp = x;

    while (temp > 0)
    {
        count++;
        temp /= 10;
    }

    temp = x;
    while (temp > 0)
    {
        rem = temp % 10;
        sum += (int)pow(rem, count);
        temp /= 10;
    }

    return (sum ==x);
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (armstrong(n))
        printf("Number is armstrong");
    else
        printf("Number is not armstrong");
    return 0;
}