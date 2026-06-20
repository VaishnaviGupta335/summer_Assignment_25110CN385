#include <stdio.h>
#include <string.h>

int main()
{
    char st1[] = "ABCD";
    char st2[] = "CDAB";

    int n = strlen(st1);
    int m = strlen(st2);

    if (n != m)
    {
        printf("Not a rotation");
        return 0;
    }

    char temp[2 * n + 1];

    strcpy(temp, st1);
    strcat(temp, st1);

    if (strstr(temp, st2) != NULL)
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");

    return 0;
}