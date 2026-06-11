#include <stdio.h>

int main(){
    int n,temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the value of:\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    temp=A[n-1];
    for (int i=n-1;i>0;i--){
        A[i]=A[i-1];
    }
    A[0]=temp;

    printf("Right rotated array:-\n");
    for (int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return 0;
}