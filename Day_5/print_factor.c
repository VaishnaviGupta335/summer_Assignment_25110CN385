#include <stdio.h>
int main()
{
    int n, i = 1, rem;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factors of %d are\n",n);
    while (i<=n/2)
    {
        rem=n%i;
        if(rem==0)
        printf("%d ",i);
        i=i+1;
    }
    printf("%d", n);
    return 0;
}