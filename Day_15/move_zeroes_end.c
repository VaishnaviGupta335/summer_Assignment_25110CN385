#include <stdio.h>

int main(){
    int n,j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the value of:\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for (int i=0;i<n;i++){
        if(A[i]!=0){
            A[j]=A[i];
            j++;
        }
    }
    while(j<n){
        A[j]=0;
        j++;
    }

    printf("Array after moving all zeroes to end is:-\n");
    for (int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return 0;
}