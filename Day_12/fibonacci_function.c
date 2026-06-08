#include <stdio.h>

void fibonacci(int);
void fibonacci(int x){
    int previousSecond=0,previousFirst=1,current;
    for (int i=1;i<=x;i++){
        printf("%d ", previousSecond);
        current=previousFirst+previousSecond;
        previousSecond=previousFirst;
        previousFirst=current;
    } return;
}

int main(){
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    fibonacci(n);
    
    return 0;
}