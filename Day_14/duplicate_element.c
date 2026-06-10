#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int already_checked = 0;

        // Check if A[i] appeared earlier
        for (int k = 0; k < i; k++)
        {
            if (A[i] == A[k])
            {
                already_checked = 1;
                break;
            }
        }

        if (already_checked)
            continue;

        // Check for duplicates after i
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] == A[j])
            {
                printf("%d is a duplicate element\n", A[i]);
                break;
            }
        }
    }

    return 0;
}