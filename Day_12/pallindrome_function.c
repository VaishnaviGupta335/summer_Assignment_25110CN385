#include <stdio.h>

int pallindrome(int);

int pallindrome(int x){
    int rem, rev=0;
    int temp=x;
    while(temp>0)
    {
        rem=temp%10;
        rev=rev*10+rem;
        temp=temp/10;
    }   
    return (x==rev);
}

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if(pallindrome(n))
    printf("Number is pallindrome");
    else
    printf("Number is not pallindrome");
    return 0;
}  