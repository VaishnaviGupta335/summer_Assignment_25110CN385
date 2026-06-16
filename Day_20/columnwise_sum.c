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
        int column_sum=0;
        for(int j=0;j<m;j++){
            column_sum+=A[j][i];
        }
        printf("Sum of elements of column %d is %d\n", i+1, column_sum);
    }
    return 0;
}