#include <stdio.h>

int sum(int,int);

int sum(int a, int b){
    return a+b;
}

int main(){
    int firstNum,secondNum;
    printf("Enter two numbers: ");
    scanf("%d %d", &firstNum, &secondNum);
    printf("Sum of numbers is %d", sum(firstNum,secondNum));
    return 0;
}