#include <stdio.h>

int sum_digits(int, int);

int sum_digits(int x, int sum){
    if (x==0){
        return sum;
    }
    return sum_digits(x/10,x%10+sum);
}


int main(){
    int n;
    printf("Enter the number: ", n);
    scanf("%d", &n);
    printf("Sum of digits = %d", sum_digits(n,0));
    return 0;
}