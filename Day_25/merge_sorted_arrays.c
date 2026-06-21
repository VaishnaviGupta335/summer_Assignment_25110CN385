#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter the number of elements: ");
    scanf("%d %d", &n, &m);

    int A[n];
    printf("Enter the value of fisrt sorted array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int B[m];
    printf("Enter the value of second sorted array\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }
  
    int C[n + m];
    int i = 0, j = 0, k = 0;
    
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < n)
        C[k++] = A[i++];

    while (j < m)
        C[k++] = B[j++];

    printf("Sorted array\n");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", C[i]);
    }
    return 0;
}