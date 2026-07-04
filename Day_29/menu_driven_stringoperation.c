#include <stdio.h>
#include <string.h>

#define MAX 100

// Input String
void inputString(char str[])
{
    printf("Enter a string: ");
    getchar(); // Clear input buffer
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
}

// Display String
void displayString(char str[])
{
    if (strlen(str) == 0)
    {
        printf("String is empty.\n");
        return;
    }

    printf("String: %s\n", str);
}

// Find Length
void stringLength(char str[])
{
    printf("Length of string = %lu\n", strlen(str));
}

// Copy String
void copyString(char str[])
{
    char copy[MAX];

    strcpy(copy, str);

    printf("Copied String: %s\n", copy);
}

// Concatenate Strings
void concatenateString(char str[])
{
    char str2[MAX];

    printf("Enter another string: ");
    getchar();
    fgets(str2, MAX, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    strcat(str, str2);

    printf("After Concatenation: %s\n", str);
}

// Compare Strings
void compareStrings(char str[])
{
    char str2[MAX];

    printf("Enter another string: ");
    getchar();
    fgets(str2, MAX, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (strcmp(str, str2) == 0)
        printf("Both strings are equal.\n");
    else
        printf("Strings are not equal.\n");
}

// Reverse String
void reverseString(char str[])
{
    char rev[MAX];
    int i, j;

    j = 0;

    for (i = strlen(str) - 1; i >= 0; i--)
    {
        rev[j++] = str[i];
    }

    rev[j] = '\0';

    printf("Reversed String: %s\n", rev);
}

// Main Function
int main()
{
    char str[MAX] = "";
    int choice;

    do
    {
        printf("\n====== STRING OPERATION SYSTEM ======\n");
        printf("1. Input String\n");
        printf("2. Display String\n");
        printf("3. Find Length\n");
        printf("4. Copy String\n");
        printf("5. Concatenate String\n");
        printf("6. Compare Strings\n");
        printf("7. Reverse String\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputString(str);
            break;

        case 2:
            displayString(str);
            break;

        case 3:
            stringLength(str);
            break;

        case 4:
            copyString(str);
            break;

        case 5:
            concatenateString(str);
            break;

        case 6:
            compareStrings(str);
            break;

        case 7:
            reverseString(str);
            break;

        case 8:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 8);

    return 0;
}