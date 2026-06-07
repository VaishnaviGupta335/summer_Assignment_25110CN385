#include <stdio.h>

int max(int,int);

int max(int a, int b){
    return (a>b)?a:b;
}

int main(){
    int firstNum,secondNum;
    printf("Enter two numbers: ");
    scanf("%d %d", &firstNum, &secondNum);
    printf("Maximum of numbers is %d", max(firstNum,secondNum));
    return 0;
}