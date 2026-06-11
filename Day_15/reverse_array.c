#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the value of:\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }
    
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = A[i];
        A[i] = A[n - 1 - i];
        A[n - 1 - i] = temp;
    }

    printf("Reverse arary:- \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}