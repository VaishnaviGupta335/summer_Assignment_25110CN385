#include <stdio.h>
int reverse(int, int);

int reverse(int x, int rev)
{
    if (x == 0)
    {
        return rev;
    }
    return reverse(x / 10, (x % 10) + rev * 10);
}

int main()
{
    int n;
    printf("Enter the number: ", n);
    scanf("%d", &n);
    printf("Reverse of number is %d", reverse(n, 0));
    return 0;
}