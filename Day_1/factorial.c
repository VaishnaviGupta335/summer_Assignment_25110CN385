#include <stdio.h>
int main()
{
    int n,i=2,fact=1;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n==0 || n==1)
    {
        printf("Factorial of %d is 1", n);
    }
    else
    {
        while(i<=n)
        {
            fact=fact*i;
            i=i+1;
        }
        printf("Factorial of %d is %d", n,fact);
    }
    return 0;
}