#include <stdio.h>

int main(){
    
    int age;
    printf("Enter the age: ");
    scanf("%d", &age);

    if (age>=18)
        printf("You are eliegible for voting");
    else
        printf("You are not eleigible for voting");
    return 0;
}