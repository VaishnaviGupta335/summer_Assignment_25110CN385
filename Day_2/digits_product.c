#include <stdio.h>
int main()
{
    int n, rem, product = 1;
    printf("Enter the number: ");
    scanf("%d", &n);
    while (n > 0)
    {
        rem=n%10;
        product=product*rem;
        n=n/10;
    }
    printf("Product of the number= %d",product);
    return 0;
}