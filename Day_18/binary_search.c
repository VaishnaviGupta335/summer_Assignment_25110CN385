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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    int low = 0;
    int high = n - 1;
    int found = 0;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(A[mid] == key)
        {
            printf("Element %d is found at index %d", key, mid);
            found = 1;
            break;
        }
        else if(key > A[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(!found)
    {
        printf("Element not found");
    }

    return 0;
}