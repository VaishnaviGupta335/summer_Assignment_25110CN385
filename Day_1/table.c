#include <stdio.h>
int main()
{
    int n,m,i=1;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Enter the limit upto which you want table of %d: ", n);
    scanf("%d", &m);
    while(i<=m)
    {
        printf("%d * %d = %d\n", n,i,n*i);
        i=i+1;
    }
    return 0;
}