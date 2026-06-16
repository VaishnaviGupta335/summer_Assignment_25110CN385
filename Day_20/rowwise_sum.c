#include <stdio.h>

int main(){
    int n, m;
    printf("Enter the number of rows and columns: ");
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

    for (int i=0;i<n;i++){
        int row_sum=0;
        for(int j=0;j<m;j++){
            row_sum+=A[i][j];
        }
        printf("Sum of elements of row %d is %d\n", i+1, row_sum);
    }
    return 0;
}