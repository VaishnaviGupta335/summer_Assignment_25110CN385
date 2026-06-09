#include <stdio.h>

int main()
{

    int n, array_sum = 0;
    float array_avg;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the value of\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++)
    {
        array_sum += A[i];
    }

    printf("Sum of array elements= %d\n", array_sum);

    array_avg = (float)array_sum /  n;
    printf("Average of array elements= %.2f", array_avg);
    return 0;
}