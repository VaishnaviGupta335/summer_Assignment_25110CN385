#include <stdio.h>
#include <math.h>
int main()
{
    int m, n, i, temp, count, rem, sum;
    printf("Enter the range: ");
    scanf("%d %d", &m, &n);
    printf("Armstrong numbers between %d and %d are\n", m, n);
    i=m;
    while (i <= n)
    {
        count=0;
        sum=0;
        temp=i;
        while (temp > 0)
        {
            count = count + 1;
            temp = temp / 10;
        }
        temp = i;
        while (temp > 0)
        {
            rem = temp % 10;
            sum = sum + pow(rem, count);
            temp = temp / 10;
        }
        if (sum == i)
            printf("%d ",i);
        i=i+1;
    }
    return 0;
}