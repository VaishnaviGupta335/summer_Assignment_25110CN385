#include <stdio.h>
int main()
{
    int n, power = 1, rem, intDecimal = 0, temp;
    printf("Enter the binary number: ");
    scanf("%d", &n);

    temp = n;
    while (n > 0)
    {
        rem = n % 10;
        intDecimal = intDecimal + rem * power;
        power = power * 2;
        n = n / 10;
    }

    printf("Decimal of %d is %d", temp, intDecimal);
    return 0;
}