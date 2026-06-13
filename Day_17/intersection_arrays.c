#include <stdio.h>

int main(){
     int n, m;
    printf("Enter the number of elements: ");
    scanf("%d %d", &n, &m);

    int A[n];
    printf("Enter the value of first array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int B[m];
    printf("Enter the value of second array\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }

    printf("Intersection of array\n");
    int C[n+m];
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i]==B[j]){
                printf("%d ", A[i]);
                break;
            }
        }
    }
    return 0;
}