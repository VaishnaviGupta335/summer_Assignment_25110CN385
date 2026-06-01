#include <stdio.h>
int main()
{
    int n, m, count = 0;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n == 0)
        printf("Total no. of digits in %d = 1", n);
    else
    {
        m=n;
        while (m > 0)
        {
            count = count + 1;
            m = m / 10;
        }
    printf("Total no. of digits in %d = %d", n, count);
    }
    return 0;
}