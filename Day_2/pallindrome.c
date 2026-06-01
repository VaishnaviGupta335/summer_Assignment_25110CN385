#include <stdio.h>
int main()
{
    int n,rem,rev=0,temp;
    printf("Enter the number: ");
    scanf("%d", &n);
    temp=n;
    while(n>0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    if(temp==rev)
    printf("Number is pallindromde");
    else
    printf("Number is not pallindromde");
    return 0;
}