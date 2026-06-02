#include <stdio.h>
int main()
{
    int n, rem, count = 0, temp;
    printf("Enter the number: ");
    scanf("%d", &n);
    temp = n;
    while (temp > 0)
    {
        rem = temp % 2;
        if (rem == 1)
            count++;
        temp = temp / 2;
    }
    printf("Binary sets count of %d = %d", n, count);
    return 0;
}