#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    char name[30];
    char phone[15];
} contact;

contact contacts[MAX];
int countContacts=0;

// Save the contacts
void save_contactFile()
{
    FILE *fp = fopen("contact.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&countContacts, sizeof(int), 1, fp);
    fwrite(contacts, sizeof(contact), countContacts, fp);

    fclose(fp);
}

// Load the contacts
void load_contactFile()
{
    FILE *fp = fopen("contact.dat", "rb");

    if (fp == NULL)
        return;

    fread(&countContacts, sizeof(int), 1, fp);
    fread(contacts, sizeof(contact), countContacts, fp);

    fclose(fp);
}

// Check for valid phone number
int validPhone(char phone[])
{
    if (strlen(phone) != 10)
        return 0;
    if (phone[0] < '6' || phone[0] > '9')
        return 0;

    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)phone[i]))
            return 0;
    }

    return 1;
}

// Make string case in sensitive
void toLower(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Add contact
void addContact()
{
    if (countContacts == MAX)
    {
        printf("No more contacts can be saved!!\n");
        return;
    }
    char number[15];
    while (1)
    {
        printf("Enter phone number: ");
        scanf(" %14s", number);
        if (!validPhone(number))
        {
            printf("Invalid phone number! Enter a valid 10-digit mobile number.\n");
            continue;
        }
        int duplicate = 0;
        for (int i = 0; i < countContacts; i++)
        {
            if (strcmp(contacts[i].phone, number) == 0)
            {
                duplicate = 1;
                break;
            }
        }
        if (duplicate)
        {
            printf("This phone number already exists!\n");
        }
        else
        {
            break;
        }
    }
    char yesorno;
    while (1)
    {
        char name[30], tempName1[30], tempName2[30];
        int found = 0;
        printf("Enter the name: ");
        scanf(" %29[^\n]", name);
        strcpy(tempName1, name);
        toLower(tempName1);
        for (int i = 0; i < countContacts; i++)
        {
            strcpy(tempName2, contacts[i].name);
            toLower(tempName2);
            if (strcmp(tempName2, tempName1) == 0)
            {
                found = 1;
                do
                {
                    printf("A contact with this name already exists.\n");
                    printf("Do you want to enter a different name? (Y/N): ");
                    scanf(" %c", &yesorno);
                    if (yesorno == 'N' || yesorno == 'n')
                    {
                        strcpy(contacts[countContacts].name, name);
                        strcpy(contacts[countContacts].phone, number);
                        countContacts++;
                        save_contactFile();
                        printf("Contact added successfully.\n");
                        return;
                    }
                    else if (yesorno == 'Y' || yesorno == 'y')
                    {
                        break;
                    }
                    else
                    {
                        printf("Invalid choice! Please enter only Y or N.\n");
                    }

                } while (1);
                break;
            }
        }
        if (found && (yesorno == 'Y' || yesorno == 'y'))
        {
            continue; // Ask for a new name
        }
        if (!found)
        {
            strcpy(contacts[countContacts].name, name);
            strcpy(contacts[countContacts].phone, number);
            countContacts++;
            save_contactFile();
            printf("Contact added successfully.\n");
            return;
        }
    }
}

// Display all contacts
void displayContacts()
{
    if (countContacts == 0)
    {
        printf("No contact found!!\n");
        return;
    }
    printf("%-30s %-15s\n",
           "Name", "Phone number");
    for (int i = 0; i < countContacts; i++)
    {
        printf("%-30s %-15s\n",
               contacts[i].name,
               contacts[i].phone);
    }
}

// Seach contact by phone number
void searchContact_byNumber()
{
    if (countContacts == 0)
    {
        printf("No contact exists!!\n");
        return;
    }
    char number[15];
    int found = 0;
    printf("Enter the phone number to search: ");
    scanf("%14s", number);
    printf("%-30s %-15s\n",
           "Name", "Phone Number");
    for (int i = 0; i < countContacts; i++)
    {
        if (strcmp(contacts[i].phone, number) == 0)
        {
            found = 1;
            printf("%-30s %-15s\n",
                   contacts[i].name,
                   contacts[i].phone);
            break;
        }
    }
    if (!found)
    {
        printf("No contact found with this phone number!\n");
    }
}

// Search contact by name
void searchContact_byName()
{
    if (countContacts == 0)
    {
        printf("No contact exists!!\n");
        return;
    }
    char name[30], tempName1[30], tempName2[30];
    int found = 0;
    printf("Enter the name to search: ");
    scanf(" %29[^\n]", name);
    strcpy(tempName1, name);
    toLower(tempName1);
    printf("%-30s %-15s\n",
           "Name", "Phone number");
    for (int i = 0; i < countContacts; i++)
    {
        strcpy(tempName2, contacts[i].name);
        toLower(tempName2);
        if (strcmp(tempName2, tempName1) == 0)
        {
            found = 1;
            printf("%-30s %-15s\n",
                   contacts[i].name,
                   contacts[i].phone);
        }
    }
    if (!found)
    {
        printf("No contact is found with this name!!\n");
    }
}

// Delete contact
void deleteContact()
{
    if (countContacts == 0)
    {
        printf("No contact exists!!\n");
        return;
    }
    char number[15];
    printf("Enter the phone number to delete: ");
    scanf("%14s", number);
    for (int i = 0; i < countContacts; i++)
    {
        if (strcmp(contacts[i].phone, number) == 0)
        {
            char choice;
            printf("\nContact Found\n");
            printf("Name  : %s\n", contacts[i].name);
            printf("Phone : %s\n", contacts[i].phone);
            printf("\nAre you sure you want to delete this contact? (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y')
            {
                for (int j = i; j < countContacts - 1; j++)
                {
                    contacts[j] = contacts[j + 1];
                }
                countContacts--;
                save_contactFile();
                printf("Contact deleted successfully!!\n");
            }
            else
            {
                printf("Deletion cancelled.\n");
            }
            return;
        }
    }
    printf("No contact with the entered number found!!\n");
}

int menu()
{
    printf("\n=========================================================\n");
    printf("             Contact Management system\n");
    printf("=========================================================\n");
    printf("1. Add a contact.\n");
    printf("2. Display all contacts.\n");
    printf("3. Search contact by number.\n");
    printf("4. Search contact by name.\n");
    printf("5. Delete contact.\n");
    printf("6. Exit.\n");
    printf("=========================================================\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    load_contactFile();
    int choice;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            displayContacts();
            break;
        case 3:
            searchContact_byNumber();
            break;
        case 4:
            searchContact_byName();
            break;
        case 5:
            deleteContact();
            break;
        case 6:
            printf("Thank you for using Contact Management System.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}