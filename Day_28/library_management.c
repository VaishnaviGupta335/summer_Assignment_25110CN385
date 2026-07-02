#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 100 

//Structure for books record
typedef struct
{
    int bookID;
    char bookName[20];
    char author[20];
    char publisher[20];
    int year;
    float price;
    int quantity;
} book;

book books[MAX];
int countBook = 0;

//Save the book records in a file
void save_bookFile()
{
    FILE *fp = fopen("book.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&countBook, sizeof(int), 1, fp);
    fwrite(books, sizeof(book), countBook, fp);

    fclose(fp);
}

//Load the book record from the file
void load_bookFile()
{
    FILE *fp = fopen("book.dat", "rb");

    if (fp == NULL)
        return;

    fread(&countBook, sizeof(int), 1, fp);
    fread(books, sizeof(book), countBook, fp);

    fclose(fp);
}

//Add books 
void addBook()
{
    if (countBook == MAX)
    {
        printf("Book database is full!!\n");
        return;
    }
    int ID;
    printf("Enter book ID: ");
    scanf("%d", &ID);
    for (int i = 0; i < countBook; i++)
    {
        if (books[i].bookID == ID)
        {
            printf("Book ID already exists!!\n");
            return;
        }
    }
    books[countBook].bookID = ID;
    printf("Enter book name: ");
    scanf(" %19[^\n]", books[countBook].bookName);
    printf("Enter author name: ");
    scanf(" %19[^\n]", books[countBook].author);
    printf("Enter publisher: ");
    scanf(" %19[^\n]", books[countBook].publisher);
    printf("Enter publishing year: ");
    scanf("%d", &books[countBook].year);
    printf("Enter price of book: ");
    scanf("%f", &books[countBook].price);
    printf("Enter quantity: ");
    scanf("%d", &books[countBook].quantity);
    countBook++;
    save_bookFile();
    printf("Book added successfully!!\n");
}

//Display the records of book
void displaybook()
{
    if (countBook == 0)
    {
        printf("No book record found!!\n");
        return;
    }
    printf("%-10s %-20s %-20s %-20s %-10s %-10s %-10s\n",
           "Book Id", "Book Name", "Author", "Publisher", "Year", "Price", "Quantity");
    for (int i = 0; i < countBook; i++)
    {
        printf("%-10d %-20s %-20s %-20s %-10d %-10.2f %-10d\n",
               books[i].bookID,
               books[i].bookName,
               books[i].author,
               books[i].publisher,
               books[i].year,
               books[i].price,
               books[i].quantity);
    }
}

//Make the character case insensitive
void toLower(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

//Search book by book name
void searchBook()
{
    if (countBook == 0)
    {
        printf("No book record found!!\n");
        return;
    }

    char name[20], tempName[20], tempBook[20];
    int found = 0;

    printf("Enter the book name to search: ");
    scanf(" %19[^\n]", name);

    strcpy(tempName, name);
    toLower(tempName);

    for (int i = 0; i < countBook; i++)
    {
        strcpy(tempBook, books[i].bookName);
        toLower(tempBook);

        if (strcmp(tempBook, tempName) == 0)
        {
            printf("%-10s %-20s %-20s %-20s %-10s %-10s %-10s\n",
                   "Book Id", "Book Name", "Author", "Publisher", "Year", "Price", "Quantity");

            printf("%-10d %-20s %-20s %-20s %-10d %-10.2f %-10d\n",
                   books[i].bookID,
                   books[i].bookName,
                   books[i].author,
                   books[i].publisher,
                   books[i].year,
                   books[i].price,
                   books[i].quantity);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found!!\n");
}
 
//Structure for date
typedef struct
{
    int date;
    int month;
    int year;
} Date;

//Structure for member record
typedef struct
{
    int memberId;
    char memberName[20];
    int bookId;
    char contact[15];
    Date dateofIssue;
    Date returnDate;
    int fine;
    int returned;
} members;

members member[MAX];
int countMember = 0;

//Save the member records in a file
void save_MemberFile()
{
    FILE *fp = fopen("member.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&countMember, sizeof(int), 1, fp);
    fwrite(member, sizeof(members), countMember, fp);

    fclose(fp);
}

//Load the member record from the file
void load_memberFile()
{
    FILE *fp = fopen("member.dat", "rb");

    if (fp == NULL)
        return;

    fread(&countMember, sizeof(int), 1, fp);
    fread(member, sizeof(members), countMember, fp);

    fclose(fp);
}

//Issue book to the members
void issueBook()
{
    if (countBook == 0)
    {
        printf("No book record found!!\n");
        return;
    }

    if (countMember == MAX)
    {
        printf("Member database is full!!\n");
        return;
    }

    char bookname[20];
    char tempInput[20], tempBook[20];
    int found = 0;

    printf("Enter the book name to issue: ");
    scanf(" %19[^\n]", bookname);

    strcpy(tempInput, bookname);
    toLower(tempInput);

    for (int i = 0; i < countBook; i++)
    {
        strcpy(tempBook, books[i].bookName);
        toLower(tempBook);

        if (strcmp(tempBook, tempInput) == 0)
        {
            found = 1;

            if (books[i].quantity > 0)
            {
                found = 2;

                int id;
                char name[20];

                printf("Enter member ID: ");
                scanf("%d", &id);

                printf("Enter member name: ");
                scanf(" %19[^\n]", name);

                // Check if Member ID belongs to another member
                for (int j = 0; j < countMember; j++)
                {
                    if (member[j].memberId == id &&
                        strcmp(member[j].memberName, name) != 0)
                    {
                        printf("This Member ID already belongs to another member!\n");
                        return;
                    }
                }

                member[countMember].memberId = id;
                strcpy(member[countMember].memberName, name);

                member[countMember].bookId = books[i].bookID;

                while (1)
                {
                    int valid = 1;

                    printf("Enter member contact number: ");
                    scanf(" %14s", member[countMember].contact);

                    if (strlen(member[countMember].contact) != 10)
                        valid = 0;

                    for (int k = 0; member[countMember].contact[k] != '\0'; k++)
                    {
                        if (!isdigit(member[countMember].contact[k]))
                        {
                            valid = 0;
                            break;
                        }
                    }

                    if (valid)
                        break;

                    printf("Invalid contact number! Please enter exactly 10 digits.\n");
                }

                printf("Enter issue date (DD MM YYYY): ");
                scanf("%d%d%d",
                      &member[countMember].dateofIssue.date,
                      &member[countMember].dateofIssue.month,
                      &member[countMember].dateofIssue.year);

                member[countMember].returned = 0;
                member[countMember].fine = 0;

                books[i].quantity--;

                countMember++;

                save_bookFile();
                save_MemberFile();

                printf("Book issued successfully!!\n");
                return;
            }
        }
    }

    if (found == 0)
        printf("Book not found!!\n");
    else if (found == 1)
        printf("Book is currently unavailable!!\n");
}

#define ALLOWED_DAYS 15
#define FINE_PER_DAY 5

//Calculate total days the book is issued
int calculateDays(Date issue, Date ret)
{
    struct tm issueDate = {0};
    struct tm returnDate = {0};

    issueDate.tm_mday = issue.date;
    issueDate.tm_mon = issue.month - 1;    // Months: 0-11
    issueDate.tm_year = issue.year - 1900; // Years since 1900

    returnDate.tm_mday = ret.date;
    returnDate.tm_mon = ret.month - 1;
    returnDate.tm_year = ret.year - 1900;

    time_t t1 = mktime(&issueDate);
    time_t t2 = mktime(&returnDate);

    double seconds = difftime(t2, t1);

    return (int)(seconds / (60 * 60 * 24));
}

//Return date and calculate fine if the book is returned late
void returnBook()
{
    if (countMember == 0)
    {
        printf("No issued books found!!\n");
        return;
    }

    int memberID;
    int found = 0;

    printf("Enter Member ID: ");
    scanf("%d", &memberID);

    for (int i = 0; i < countMember; i++)
    {
        if (member[i].memberId == memberID)
        {
            found = 1;
            if (member[i].returned == 1)
            {
                printf("Book already returned!\n");
                return;
            }

            Date returnDate;

            printf("Enter return date (DD MM YYYY): ");
            scanf("%d%d%d",
                  &returnDate.date,
                  &returnDate.month,
                  &returnDate.year);

            int days = calculateDays(member[i].dateofIssue, returnDate);

            if (days < 0)
            {
                printf("Invalid return date!\n");
                return;
            }

            int fine = 0;

            if (days > ALLOWED_DAYS)
            {
                fine = (days - ALLOWED_DAYS) * FINE_PER_DAY;
            }

            // Increase book quantity
            for (int j = 0; j < countBook; j++)
            {
                if (books[j].bookID == member[i].bookId)
                {
                    books[j].quantity++;
                    break;
                }
            }

            printf("\nBook returned successfully!\n");
            printf("Book kept for %d days\n", days);
            printf("Fine = Rs. %d\n", fine);

            // Remove member record
            member[i].returnDate = returnDate;
            member[i].fine = fine;
            member[i].returned = 1;

            save_bookFile();
            save_MemberFile();

            return;
        }
    }

    if (!found)
    {
        printf("Member ID not found!!\n");
    }
}

//Display the records of member
void displayMember()
{
    if (countMember == 0)
    {
        printf("No member record found!!\n");
        return;
    }

    printf("%-10s %-20s %-8s %-12s %-12s %-12s %-8s %-10s\n",
           "MemberID", "Member Name", "BookID", "Contact",
           "Issue Date", "Return Date", "Fine", "Status");

    for (int i = 0; i < countMember; i++)
    {
        printf("%-10d %-20s %-8d %-12s ",
               member[i].memberId,
               member[i].memberName,
               member[i].bookId,
               member[i].contact);

        printf("%02d/%02d/%04d   ",
               member[i].dateofIssue.date,
               member[i].dateofIssue.month,
               member[i].dateofIssue.year);

        if (member[i].returned)
        {
            printf("%02d/%02d/%04d   %-8d %-10s\n",
                   member[i].returnDate.date,
                   member[i].returnDate.month,
                   member[i].returnDate.year,
                   member[i].fine,
                "Returned");
        }
        else
        {
            printf("%-12s %-8s %-10s\n",
                   "--/--/----",
                   0,
                "Issued");
        }
    }
}

//Delete any member record by member ID
void deleteMember()
{
    if (countMember == 0)
    {
        printf("No member record found!!\n");
        return;
    }

    int id, found = 0;

    printf("Enter Member ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < countMember; i++)
    {
        if (member[i].memberId == id)
        {
            found = 1;

            if (member[i].returned == 0)
            {
                printf("This member has not returned the book yet.\n");
                printf("Cannot delete the member record.\n");
                return;
            }

            for (int j = i; j < countMember - 1; j++)
            {
                member[j] = member[j + 1];
            }

            countMember--;

            save_MemberFile();

            printf("Member record deleted successfully!!\n");
            return;
        }
    }

    if (!found)
    {
        printf("Member ID not found!!\n");
    }
}

//Delte the book record by book ID
void deleteBook()
{
    if (countBook == 0)
    {
        printf("No book record found!!\n");
        return;
    }
    int id, found = 0;
    printf("Enter the book id to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < countMember; i++)
    {
        if (member[i].bookId == id && member[i].returned == 0)
        {
            printf("Book is currently issued. Cannot delete.\n");
            return;
        }
    }
    for (int i = 0; i < countBook; i++)
    {
        if (books[i].bookID == id)
        {
            found = 1;
            for (int j = i; j < countBook - 1; j++)
            {
                books[j] = books[j + 1];
            }
            countBook--;
            save_bookFile();
            printf("Book deleted succesfully!!\n");
            break;
        }
    }
    if (found == 0)
    {
        printf("Book not found!!\n");
    }
}

//main function
int main()
{

    load_bookFile();
    load_memberFile();

    int choice = 0;
    while (choice != 9)
    {
        printf("\n===== Library Management System =====\n");
        printf("1. Add books.\n");
        printf("2. Display book database.\n");
        printf("3. Delete book.\n");
        printf("4. Search book.\n");
        printf("5. Issue book.\n");
        printf("6. Display member.\n");
        printf("7. Return book.\n");
        printf("8. Delete Member.\n");
        printf("9. Exit.\n\n");

        printf("Enter the choice(1-9): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displaybook();
            break;
        case 3:
            deleteBook();
            break;
        case 4:
            searchBook();
            break;
        case 5:
            issueBook();
            break;
        case 6:
            displayMember();
            break;
        case 7:
            returnBook();
            break;
        case 8:
            deleteMember();
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