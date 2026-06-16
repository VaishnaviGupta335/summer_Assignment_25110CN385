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

    int found=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j]!=A[j][i]){
                found=0;
                printf("Matrix are not symmetric");
                break;
            }
        }
        if (!found)
        break;
    }
    if (found)
    printf("Matrix are symmetric");
    return 0;
}