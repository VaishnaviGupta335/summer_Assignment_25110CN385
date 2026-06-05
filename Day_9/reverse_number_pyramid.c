#include <stdio.h>

int main(){
    int n;
    printf("enter the number of rows: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int a=1;
        for(int j=n+1-i; j>=1;j--){
            printf("%d",a);
            a++;
        }
        printf("\n");
    }
    return 0;
}