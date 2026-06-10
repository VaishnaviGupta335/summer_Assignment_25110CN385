#include <stdio.h>

int main()
{
    int n, element, count;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the value of\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Enter the element to find frequency: \n");
    scanf("%d", &element);

    for (int i = 0; i < n; i++)
    {
        if (A[i] == element)
        {
            count += 1;
        }
    }
    printf("Frequency of element %d is %d", element, count);
    return 0;
}