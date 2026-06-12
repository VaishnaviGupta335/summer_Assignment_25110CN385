#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elemenst\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int given_sum,pair_found=0;
    printf("Enter the target sum: ");
    scanf("%d", &given_sum);

    printf("Pairs are:-\n");
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(A[i]+A[j]==given_sum){
                printf("%d and %d\n",A[i],A[j]);
                pair_found=1;
            }
        }
    }
    if(pair_found==0){
        printf("No fair found");
    }
    return 0;
}