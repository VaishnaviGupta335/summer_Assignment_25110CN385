#include <stdio.h>

int main(){
    int n;
    printf("enter length of square: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((j==1 && i<=n) || ((j>=2 && j<=(n-1)) && (i==1 || i==n)) || (j==n && i<=n))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}