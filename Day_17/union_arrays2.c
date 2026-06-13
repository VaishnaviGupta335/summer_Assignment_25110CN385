#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter the number of elements: ");
    scanf("%d %d", &n, &m);

    int A[n], B[m];
    
    printf("Enter the value of first array \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    printf("Enter the value of second array \n");
    for (int i = 0; i < m; i++){
        scanf("%d", &B[i]);
    }

    int C[n + m];
    int k = 0;

    // Process A
    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < k; j++)
        {
            if (A[i] == C[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
            C[k++] = A[i];
    }

    // Process B
    for (int i = 0; i < m; i++)
    {
        int found = 0;

        for (int j = 0; j < k; j++)
        {
            if (B[i] == C[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
            C[k++] = B[i];
    }

    printf("Union of array\n");
    for (int i = 0; i < k; i++){
        printf("%d ", C[i]);
    }
    return 0;
}