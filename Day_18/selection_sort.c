#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the elements\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }

    printf("Sorted array\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}