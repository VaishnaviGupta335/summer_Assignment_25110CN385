#include <stdio.h>

int main()
{
    int choice, balance = 6000;
    do
    {
        printf("******ATM Menu******\n");
        printf("1. Check balance.\n");
        printf("2. Deposit money.\n");
        printf("3. Withdraw money.\n");
        printf("4. Exit.\n");
        printf("********************\n");
        int amount_deposited, amount_withdrawn;

        printf("Enter the choice(1-4) from the menu: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Your current balance is %d!!\n", balance);
            break;

        case 2:
            printf("Enter amount to deposit: ");
            scanf("%d", &amount_deposited);
            printf("Rupees %d is deposited in your account!!\n",  amount_deposited);
            balance += amount_deposited;
            printf("Now your current balance is %d.\n", balance);
            break;

        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount_withdrawn);
            if (amount_withdrawn > balance)
            {
                printf("You have not sufficient balance.\nYou can't withdraw.\n");
            }
            else
            {
                printf("Rupees %d is withdrawn!!\n", amount_withdrawn);
                balance -= amount_withdrawn;
                printf("Now your current balance is %d.\n", balance);
            }
            break;

        case 4:
            printf("Thanyou for using ATM!!");
            break;

        default:
            printf("Invalid choice!!\n");
        }
        printf("\n");
        if (choice!=4)
            printf("Is there anything else you would like to do?\n");
    } 
    while (choice != 4);

    return 0;
}