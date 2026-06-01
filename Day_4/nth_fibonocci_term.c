#include <stdio.h>
int main()
{
    int n, previousFisrt = 1, previousSecond = 0, current,i=3;
    printf("Enter the term: ");
    scanf("%d", &n);
    if (n == 1)
        printf("%d", previousSecond);
    else if (n == 2)
        printf("%d", previousFisrt);
    else
    {
        while (i <= n)
        {
            current = previousFisrt + previousSecond;
            previousSecond = previousFisrt;
            previousFisrt = current;
            i=i+1;
        }
        printf("%d ", current);
    }
    return 0;
}