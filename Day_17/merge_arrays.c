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

    int C[n + m],i=0;
    for (i = 0; i < n; i++)
    {
        C[i] = A[i];
    }
    
    for (int j = 0; j < m; j++)
    {
        C[i] = B[j];
        i++;
    }
    
    printf("Merged array\n");
    for (int i=0;i<n+m;i++){
        printf("%d ", C[i]);
    }
    return 0;
}