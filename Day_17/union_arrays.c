#include <stdio.h>

int main()
{
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

    int l=n+m;
    int C[l],i;
    for (i = 0; i < n; i++)
    {
        C[i] = A[i];
    }
    
    for (int j = 0; j < m; j++)
    {
        C[i] = B[j];
        i++;
    }
    
    for (int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if (C[i]==C[j]){
                for(int k=j;k<l-1;k++){
                    C[k]=C[k+1];
                }
                l--;
                j--;
            }
        }
    }

    printf("Union of array\n");
    for (int i=0;i<l;i++){
        printf("%d ", C[i]);
    }
    return 0;
}