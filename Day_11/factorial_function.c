#include <stdio.h>

int factorial(int);

int factorial(int x){
    int fact=1;
    for(int i=1;i<=x;i++){
        fact*=i;
    }
    return fact;
}

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Factorial pf %d is %d", n, factorial(n));
    return 0;
}