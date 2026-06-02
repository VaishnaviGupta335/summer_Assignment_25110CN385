#include <stdio.h>
int main()
{
    float n, fracPart;
    int intPart, binary[32], i = 0, j, count = 0;
    printf("Enter the decimal number: ");
    scanf("%f", &n);

    intPart = (int)n;
    fracPart = n - intPart;

    while (intPart > 0)
    {
        binary[i] = intPart % 2;
        intPart = intPart / 2;
        i++;
    }

    printf("Binary of %d is\n", n);

    for (j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);


    if (fracPart > 0)
    {
        printf(".");
        while (fracPart > 0 && count < 10)
        {
            fracPart = fracPart * 2;
            if (fracPart >= 1)
            {
                printf("1");
                fracPart = fracPart - 1;
            }
            else
                printf("0");
            count++;
        }
    }
    return 0;
}