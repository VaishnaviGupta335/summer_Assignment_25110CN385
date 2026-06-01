#include <stdio.h>
#include <math.h>
int main()
{
    int n, temp, count = 0, rem, sum = 0;
    printf("Enter the number: ");
    scanf("%d", &n);
    temp = n;
    while (temp > 0)
    {
        count = count + 1;
        temp = temp / 10;
    }
    temp = n;
    while (temp > 0)
    {
        rem = temp % 10;
        sum = sum + pow(rem, count);
        temp = temp / 10;
    }
    if (sum == n)
        printf("Number is armstrong");
    else
        printf("Number is not armstrong");
    return 0;
}