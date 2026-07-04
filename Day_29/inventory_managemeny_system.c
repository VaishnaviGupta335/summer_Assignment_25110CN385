#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int id;
    char name[30];
    float price;
    int quantity;
} Product;

Product products[MAX];
int count = 0;

// Add Product
void addProduct()
{
    if (count == MAX)
    {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &products[count].id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", products[count].name);

    printf("Enter Price: ");
    scanf("%f", &products[count].price);

    printf("Enter Quantity: ");
    scanf("%d", &products[count].quantity);

    count++;

    printf("Product added successfully.\n");
}

// Display Products
void displayProducts()
{
    int i;

    if (count == 0)
    {
        printf("No products available.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("%-10s %-25s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-10d %-25s %-10.2f %-10d\n",
               products[i].id,
               products[i].name,
               products[i].price,
               products[i].quantity);
    }
}

// Search Product
void searchProduct()
{
    int id, i;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("\nProduct Found\n");
            printf("ID       : %d\n", products[i].id);
            printf("Name     : %s\n", products[i].name);
            printf("Price    : %.2f\n", products[i].price);
            printf("Quantity : %d\n", products[i].quantity);
            return;
        }
    }

    printf("Product not found.\n");
}

// Update Product
void updateProduct()
{
    int id, i;

    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", products[i].name);

            printf("Enter New Price: ");
            scanf("%f", &products[i].price);

            printf("Enter New Quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Product updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

// Delete Product
void deleteProduct()
{
    int id, i, j;

    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            for (j = i; j < count - 1; j++)
            {
                products[j] = products[j + 1];
            }

            count--;

            printf("Product deleted successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

// Restock Product
void restockProduct()
{
    int id, qty, i;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("Enter quantity to add: ");
            scanf("%d", &qty);

            products[i].quantity += qty;

            printf("Stock updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

// Sell Product
void sellProduct()
{
    int id, qty, i;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("Enter quantity to sell: ");
            scanf("%d", &qty);

            if (qty > products[i].quantity)
            {
                printf("Insufficient stock.\n");
            }
            else
            {
                products[i].quantity -= qty;
                printf("Product sold successfully.\n");
            }
            return;
        }
    }

    printf("Product not found.\n");
}

// Total Inventory Value
void totalInventoryValue()
{
    int i;
    float total = 0;

    for (i = 0; i < count; i++)
    {
        total += products[i].price * products[i].quantity;
    }

    printf("Total Inventory Value = %.2f\n", total);
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n========== INVENTORY MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Restock Product\n");
        printf("7. Sell Product\n");
        printf("8. Total Inventory Value\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addProduct();
            break;

        case 2:
            displayProducts();
            break;

        case 3:
            searchProduct();
            break;

        case 4:
            updateProduct();
            break;

        case 5:
            deleteProduct();
            break;

        case 6:
            restockProduct();
            break;

        case 7:
            sellProduct();
            break;

        case 8:
            totalInventoryValue();
            break;

        case 9:
            printf("Thank you!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 9);

    return 0;
}