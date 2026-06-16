#include <stdio.h>

int main()
{
    int n;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int diagonal_sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || (i + j) == (n - 1))
                diagonal_sum += A[i][j];
        }
    }
    printf("Duagonal sum= %d", diagonal_sum);
    return 0;
}