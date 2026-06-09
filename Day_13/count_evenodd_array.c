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

    int even_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            even_count += 1;
        }
    }
    printf("Number of even elements in c= %d\n", even_count);
    printf("Number of odd elements in c= %d\n", (n - even_count));

    return 0;
}