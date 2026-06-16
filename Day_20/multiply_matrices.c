#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &n, &m);

    int A[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int x, y;
    printf("Enter the number of rows and columns of matrix  2: ");
    scanf("%d %d", &x, &y);

    int B[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    int C[n][y];
    if (m != x)
        printf("Multiplication is not possible");
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < y; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < m; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    printf("Multiplication of matrices\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}