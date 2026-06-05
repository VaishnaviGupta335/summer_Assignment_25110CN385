#include <stdio.h>

int factorial(int);

int factorial(int x)
{
    int fact;
    if (x==1 || x==0){
    return 1;
    }
    fact=factorial(x-1)*x;
    return fact;
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d", n, factorial(n));
    return 0;
}