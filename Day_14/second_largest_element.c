#include <stdio.h>
#include <limits.h>

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

    //Check for largest element
    int lar_element = A[0];
    for (int i = 0; i < n; i++)
    {
        if (lar_element < A[i])
        {
            lar_element = A[i];
        }
    }

    //Check for second largest element
    int sec_lar_element =INT_MIN; 
    for (int i = 0; i < n; i++)
    {
        if (A[i] != lar_element)
        {
            if (sec_lar_element < A[i])
            {
                sec_lar_element = A[i];
            }
        }
    }
    printf("Second largest element of array is %d\n", sec_lar_element);
    return 0;
}