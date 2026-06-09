#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the value of\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    int lar_element = A[0];
    for (int i = 0; i < n; i++)
    {
        if (lar_element < A[i])
        {
            lar_element = A[i];
        }
    }
    printf("Largest element of array is %d\n", lar_element);

    int small_element = A[0];
    for (int i = 0; i < n; i++)
    {
        if (small_element > A[i])
        {
            small_element = A[i];
        }
    }
    printf("Smallest element of array is %d", small_element);
    return 0;
}