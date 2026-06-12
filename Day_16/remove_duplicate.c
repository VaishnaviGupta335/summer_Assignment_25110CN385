#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (A[i]==A[j]){
                for(int k=j;k<n-1;k++){
                    A[k]=A[k+1];
                }
                n--;
                j--;
            }
        }
    }

    printf("New array is\n");
    for (int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return 0;
}