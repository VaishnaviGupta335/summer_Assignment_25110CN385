#include<stdio.h>
int main()
{
    int x,n,temp;
    printf("Enter the number and power: ");
    scanf("%d %d", &x, &n);
    temp=x;
    for(int i=1;i<n;i++)
    {
        temp=temp*x;
    }
    printf("%d to the power %d = %d", x, n, temp);
    return 0;
}