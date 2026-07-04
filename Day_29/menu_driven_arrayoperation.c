#include <stdio.h>

#define MAX 100

// Insert Elements
void insert(int arr[], int *n)
{
    int i;

    printf("How many elements do you want to insert? ");
    scanf("%d", n);

    if (*n > MAX)
    {
        printf("Array size exceeds limit!\n");
        *n = 0;
        return;
    }

    printf("Enter %d elements:\n", *n);

    for (i = 0; i < *n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Elements inserted successfully.\n");
}

// Display Array
void display(int arr[], int n)
{
    int i;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("\nArray Elements:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Search Element
void search(int arr[], int n)
{
    int value, i;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &value);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("Element found at position %d.\n", i + 1);
            return;
        }
    }

    printf("Element not found.\n");
}

// Update Element
void update(int arr[], int n)
{
    int pos, value;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter position to update (1-%d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    arr[pos - 1] = value;

    printf("Element updated successfully.\n");
}

// Delete Element
void deleteElement(int arr[], int *n)
{
    int pos, i;

    if (*n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter position to delete (1-%d): ", *n);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
    {
        printf("Invalid position.\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully.\n");
}

// Find Maximum Element
void findMax(int arr[], int n)
{
    int i, max;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Maximum Element = %d\n", max);
}

// Find Minimum Element
void findMin(int arr[], int n)
{
    int i, min;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    min = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Minimum Element = %d\n", min);
}

// Sort Array
void sortArray(int arr[], int n)
{
    int i, j, temp;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array sorted successfully.\n");
}

// Main Function
int main()
{
    int arr[MAX];
    int n = 0;
    int choice;

    do
    {
        printf("\n========== ARRAY OPERATION SYSTEM ==========\n");
        printf("1. Insert Elements\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");
        printf("4. Update Element\n");
        printf("5. Delete Element\n");
        printf("6. Find Maximum Element\n");
        printf("7. Find Minimum Element\n");
        printf("8. Sort Array\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(arr, &n);
            break;

        case 2:
            display(arr, n);
            break;

        case 3:
            search(arr, n);
            break;

        case 4:
            update(arr, n);
            break;

        case 5:
            deleteElement(arr, &n);
            break;

        case 6:
            findMax(arr, n);
            break;

        case 7:
            findMin(arr, n);
            break;

        case 8:
            sortArray(arr, n);
            break;

        case 9:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}