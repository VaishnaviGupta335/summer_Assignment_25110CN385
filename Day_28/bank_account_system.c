#include <stdio.h>

// Structure for
typedef struct
{
    int accountNo;
    char name[30];
    char phone[15];
    char address[50];
    char accountType[15]; // Savings or Current
    float balance;
} account;

#define MAX 100
account accounts[MAX];
int countAccounts = 0;

// Save the records of account holder in a file
void save_accountFile()
{
    FILE *fp = fopen("accounts.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&countAccounts, sizeof(int), 1, fp);
    fwrite(accounts, sizeof(account), countAccounts, fp);

    fclose(fp);
}

// Load the records of accout holder from the file
void load_accountFile()
{
    FILE *fp = fopen("accounts.dat", "rb");

    if (fp == NULL)
        return;

    fread(&countAccounts, sizeof(int), 1, fp);
    fread(accounts, sizeof(account), countAccounts, fp);

    fclose(fp);
}

// Add user in the accounts
void addAccount()
{
    if (countAccounts == MAX)
    {
        printf("Accounts database is full!!\n");
        return;
    }
    int acc;
    while (1)
    {
        int found = 0;
        printf("Enter account number (6-8 digits): ");
        scanf("%d", &acc);
        if (acc < 100000 || acc > 99999999)
        {
            printf("Invalid account number! Please enter a 6 to 8 digit account number.\n");
            continue;
        }
        for (int i = 0; i < countAccounts; i++)
        {
            if (accounts[i].accountNo == acc)
            {
                found = 1;
                printf("Account number already exists! Please enter a different account number.\n");
                break;
            }
        }
        if (!found)
            break;
    }
    accounts[countAccounts].accountNo = acc;
    printf("Enter name of account holder: ");
    scanf(" %29[^\n]", accounts[countAccounts].name);
    printf("Enter phone number: ");
    scanf(" %14s", accounts[countAccounts].phone);
    printf("Enter address: ");
    scanf(" %49[^\n]", accounts[countAccounts].address);
    printf("Enter account type(Savings/Current): ");
    scanf(" %14[^\n]", accounts[countAccounts].accountType);
    printf("Enter balance: ");
    scanf("%f", &accounts[countAccounts].balance);
    countAccounts++;
    save_accountFile();
    printf("Account added successfully!!\n");
}

// Display accounts
void displayAccounts()
{
    if (countAccounts == 0)
    {
        printf("No account is found!!\n");
        return;
    }
    printf("%-15s %-30s %-15s %-50s %-15s %-10s\n",
           "Account number", "Name", "Phone number", "Address", "Account type", "Balance");
    for (int i = 0; i < countAccounts; i++)
    {
        printf("%-15d %-30s %-15s %-50s %-15s %-10.2f\n",
               accounts[i].accountNo,
               accounts[i].name,
               accounts[i].phone,
               accounts[i].address,
               accounts[i].accountType,
               accounts[i].balance);
    }
}

// Search account by account number
void searchAccount()
{
    if (countAccounts == 0)
    {
        printf("No account is found!!\n");
        return;
    }
    int acc, found = 0;
    printf("Enter the account number to search: ");
    scanf("%d", &acc);
    for (int i = 0; i < countAccounts; i++)
    {
        if (acc == accounts[i].accountNo)
        {
            found = 1;
            printf("%-15s %-30s %-15s %-50s %-15s %-10s\n",
                   "Account number", "Name", "Phone number", "Address", "Account type", "Balance");
            printf("%-15d %-30s %-15s %-50s %-15s %-10.2f\n",
                   accounts[i].accountNo,
                   accounts[i].name,
                   accounts[i].phone,
                   accounts[i].address,
                   accounts[i].accountType,
                   accounts[i].balance);
            break;
        }
    }
    if (!found)
        printf("No account found!!\n");
}

// Deposit Money
void depositMoney()
{
    int acc, found = 0;
    float depositAmout;
    printf("Enter the account number to depsoit money: ");
    scanf("%d", &acc);
    for (int i = 0; i < countAccounts; i++)
    {
        if (acc == accounts[i].accountNo)
        {
            found = 1;
            while (1)
            {
                printf("Enter the amount to deposit: ");
                scanf("%f", &depositAmout);
                if (depositAmout <= 0)
                {
                    printf("Enter a valid deposit amount.\n");
                    continue;
                }
                break;
            }
            accounts[i].balance += depositAmout;
            printf("Deposit successful!!\n", depositAmout);
            printf("Now current balance: %.2f\n", accounts[i].balance);
            save_accountFile();
            return;
        }
    }
    if (!found)
        printf("No account found!!\n");
}

// Withdraw money
void withdrawMoney()
{
    int acc, found = 0;
    float withdrawAmout;
    printf("Enter the account number to withdraw money: ");
    scanf("%d", &acc);
    for (int i = 0; i < countAccounts; i++)
    {
        if (acc == accounts[i].accountNo)
        {
            found = 1;
            printf("Your current balance is %.2f\n", accounts[i].balance);
            while (1)
            {
                printf("Enter the amount to withdraw: ");
                scanf("%f", &withdrawAmout);
                if (withdrawAmout <= 0)
                {
                    printf("Enter a valid withdrawal amount.\n");
                    continue;
                }
                if (withdrawAmout > accounts[i].balance)
                {
                    printf("Sorry!! You can't withdraw this amount.\n");
                    printf("Please enter an amount less than or equal to %.2f\n",
                           accounts[i].balance);
                    continue;
                }
                break;
            }
            accounts[i].balance -= withdrawAmout;
            printf("Withdrawal successful!!\n");
            printf("Now remaining balance: %.2f\n", accounts[i].balance);
            save_accountFile();
            return;
        }
    }
    if (!found)
        printf("No account found!!\n");
}

// check balance
void checkBalance()
{
    int acc, found = 0;
    printf("Enter the account number to check balance: ");
    scanf("%d", &acc);
    for (int i = 0; i < countAccounts; i++)
    {
        if (acc == accounts[i].accountNo)
        {
            found = 1;
            printf("Your current balance is %.2f\n", accounts[i].balance);
            break;
        }
    }
    if (!found)
        printf("No account found!!\n");
}

// Update phone number
void updatePhone(int index)
{
    printf("Enter the new number: ");
    scanf(" %14s", accounts[index].phone);
    printf("Phone number is updated!!\n");
    save_accountFile();
}

// Update address
void updateAddress(int index)
{
    printf("Enter the new address: ");
    scanf(" %49[^\n]", accounts[index].address);
    printf("Address is updated!!\n");
    save_accountFile();
}

// Update account
void updateAccount()
{
    int acc, found = 0;
    printf("Enter the account number to update: ");
    scanf("%d", &acc);
    for (int i = 0; i < countAccounts; i++)
    {
        if (acc == accounts[i].accountNo)
        {
            found = 1;
            int choice = 0;
            while (choice != 3)
            {
                printf("\nWhat you want to update.\n");
                printf("1. Phone number.\n");
                printf("2. Address.\n");
                printf("3. Exit updating.\n");

                printf("Enter the choice(1-3): ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    updatePhone(i);
                    break;
                case 2:
                    updateAddress(i);
                    break;
                case 3:
                    printf("Exiting from update section.\n");
                    break;
                default:
                    printf("Invalid choice!!\n");
                    break;
                }
                if (choice != 3)
                    printf("Anything else you want to update!!\n");
            }
            return;
        }
    }
    if (!found)
        printf("No account found!!\n");
}

// Delete account
void deleteAccount()
{
    if (countAccounts == 0)
    {
        printf("No account is found!!\n");
        return;
    }
    int acc;
    printf("Enter the account number to delete: ");
    scanf("%d", &acc);
    for (int i = 0; i < countAccounts; i++)
    {
        if (accounts[i].accountNo == acc)
        {
            for (int j = i; j < countAccounts - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }
            countAccounts--;
            save_accountFile();
            printf("Account deleted successfully!!\n");
            return;
        }
    }
    printf("Account not found!!\n");
}

int main()
{

    load_accountFile();

    int choice = 0;
    while (choice != 9)
    {
        printf("\n===== Bank Account Management System =====\n");
        printf("1. Add account..\n");
        printf("2. Display accounts.\n");
        printf("3. Search account.\n");
        printf("4. Deposit money.\n");
        printf("5. Withdraw money.\n");
        printf("6. Check balance.\n");
        printf("7. Update details.\n");
        printf("8. Delete account.\n");
        printf("9. Exit.\n");
        printf("=============================================\n");

        printf("Enter the choice(1-9): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addAccount();
            break;
        case 2:
            displayAccounts();
            break;
        case 3:
            searchAccount();
            break;
        case 4:
            depositMoney();
            break;
        case 5:
            withdrawMoney();
            break;
        case 6:
            checkBalance();
            break;
        case 7:
            updateAccount();
            break;
        case 8:
            deleteAccount();
            break;
        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!!\n");
        }
    }
    return 0;
}