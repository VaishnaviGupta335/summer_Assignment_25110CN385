#include <stdio.h>

void fibonacci(int x, int a, int b)
{
    if (x <= 0)
        return;

    int c = a + b;
    printf("%d ", c);

    fibonacci(x - 1, b, c);
}

int main()
{
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n >= 1)
        printf("0 ");

    if (n >= 2)
        printf("1 ");

    fibonacci(n - 2, 0, 1);

    return 0;
}