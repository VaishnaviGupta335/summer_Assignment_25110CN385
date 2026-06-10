#include <stdio.h>

int main()
{
    int n, element, found = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the value of\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Enter the element to search: \n");
    scanf("%d", &element);

    for (int i = 0; i < n; i++)
    {
        if (A[i] == element)
        {
            found = 1;
            printf("The element %d is found at A[%d]", element, i);
            break;
        }
    }
    if (found == 0)
    {
        printf("The element %d is not found", element);
    }
    return 0;
}