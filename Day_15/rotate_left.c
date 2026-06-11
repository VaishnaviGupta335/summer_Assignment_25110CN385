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

    temp=A[0];
    for (int i=0;i<n-1;i++){
        A[i]=A[i+1];
    }
    A[n-1]=temp;

    printf("Left rotated array:-\n");
    for (int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    return 0;
}