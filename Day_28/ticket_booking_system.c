#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRAINS 50
#define MAX_BOOKINGS 200
#define TRAIN_FILE "trains.dat"
#define BOOKING_FILE "bookings.dat"
#define NAME_LEN 50
#define CITY_LEN 30
#define STATUS_LEN 12

typedef struct
{
    int trainId;
    char name[NAME_LEN];
    char source[CITY_LEN];
    char destination[CITY_LEN];
    int totalSeats;
    int availableSeats;
    float fare;
} Train;

typedef struct
{
    int pnr;
    char passengerName[NAME_LEN];
    int age;
    char gender; /* 'M' / 'F' / 'O' */
    int trainId;
    int seatNumber;
    char status[STATUS_LEN]; /* "CONFIRMED" or "CANCELLED" */
} Booking;

/* ---------------------------- Globals ---------------------------- */

Train trains[MAX_TRAINS];
int trainCount = 0;

Booking bookings[MAX_BOOKINGS];
int bookingCount = 0;

int nextPNR = 1000; /* PNR auto-increment seed */

/* ---------------------------- Utility Functions ---------------------------- */

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void pause_screen(void)
{
    printf("\nPress Enter to continue...");
    clearInputBuffer();
}

void readLine(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }
}

void toLowerStr(char *dest, const char *src)
{
    int i = 0;
    for (; src[i]; i++)
        dest[i] = (char)tolower((unsigned char)src[i]);
    dest[i] = '\0';
}

/* ---------------------------- Persistence ---------------------------- */

void loadTrains(void)
{
    FILE *fp = fopen(TRAIN_FILE, "rb");
    if (!fp)
    {
        trainCount = 0;
        return;
    }
    trainCount = (int)fread(trains, sizeof(Train), MAX_TRAINS, fp);
    fclose(fp);
}

void saveTrains(void)
{
    FILE *fp = fopen(TRAIN_FILE, "wb");
    if (!fp)
    {
        printf("Error: could not save trains.\n");
        return;
    }
    fwrite(trains, sizeof(Train), trainCount, fp);
    fclose(fp);
}

void loadBookings(void)
{
    FILE *fp = fopen(BOOKING_FILE, "rb");
    if (!fp)
    {
        bookingCount = 0;
        return;
    }
    bookingCount = (int)fread(bookings, sizeof(Booking), MAX_BOOKINGS, fp);
    fclose(fp);

    /* Recompute nextPNR from existing data so PNRs stay unique across runs */
    for (int i = 0; i < bookingCount; i++)
    {
        if (bookings[i].pnr >= nextPNR)
            nextPNR = bookings[i].pnr + 1;
    }
}

void saveBookings(void)
{
    FILE *fp = fopen(BOOKING_FILE, "wb");
    if (!fp)
    {
        printf("Error: could not save bookings.\n");
        return;
    }
    fwrite(bookings, sizeof(Booking), bookingCount, fp);
    fclose(fp);
}

/* ---------------------------- Train Management (Admin) ---------------------------- */

int findTrainIndexById(int trainId)
{
    for (int i = 0; i < trainCount; i++)
        if (trains[i].trainId == trainId)
            return i;
    return -1;
}

void addTrain(void)
{
    if (trainCount >= MAX_TRAINS)
    {
        printf("Train list is full. Cannot add more trains.\n");
        return;
    }

    Train t;
    printf("\n--- Add New Train ---\n");

    printf("Train ID (unique number): ");
    scanf("%d", &t.trainId);
    clearInputBuffer();

    if (findTrainIndexById(t.trainId) != -1)
    {
        printf("A train with this ID already exists.\n");
        return;
    }

    printf("Train Name: ");
    readLine(t.name, NAME_LEN);

    printf("Source City: ");
    readLine(t.source, CITY_LEN);

    printf("Destination City: ");
    readLine(t.destination, CITY_LEN);

    printf("Total Seats: ");
    scanf("%d", &t.totalSeats);

    printf("Fare per seat: ");
    scanf("%f", &t.fare);
    clearInputBuffer();

    t.availableSeats = t.totalSeats;

    trains[trainCount++] = t;
    saveTrains();

    printf("\nTrain added successfully!\n");
}

void printTrainHeader(void)
{
    printf("%-5s %-20s %-15s %-15s %-8s %-10s %-8s\n",
           "ID", "Name", "From", "To", "Total", "Available", "Fare");
    printf("---------------------------------------------------------------------------\n");
}

void printTrainRow(const Train *t)
{
    printf("%-5d %-20s %-15s %-15s %-8d %-10d %-8.2f\n",
           t->trainId, t->name, t->source, t->destination,
           t->totalSeats, t->availableSeats, t->fare);
}

void viewAllTrains(void)
{
    printf("\n--- All Trains ---\n");
    if (trainCount == 0)
    {
        printf("No trains available in the system.\n");
        return;
    }
    printTrainHeader();
    for (int i = 0; i < trainCount; i++)
        printTrainRow(&trains[i]);
}

/* ---------------------------- Search (User) ---------------------------- */

void searchTrains(void)
{
    char src[CITY_LEN], dst[CITY_LEN];
    char srcLower[CITY_LEN], dstLower[CITY_LEN];
    char rowSrcLower[CITY_LEN], rowDstLower[CITY_LEN];
    int found = 0;

    printf("\n--- Search Trains ---\n");
    printf("Source City: ");
    readLine(src, CITY_LEN);
    printf("Destination City: ");
    readLine(dst, CITY_LEN);

    toLowerStr(srcLower, src);
    toLowerStr(dstLower, dst);

    printTrainHeader();
    for (int i = 0; i < trainCount; i++)
    {
        toLowerStr(rowSrcLower, trains[i].source);
        toLowerStr(rowDstLower, trains[i].destination);
        if (strcmp(rowSrcLower, srcLower) == 0 && strcmp(rowDstLower, dstLower) == 0)
        {
            printTrainRow(&trains[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No trains found for that route.\n");
}

/* ---------------------------- Booking (User) ---------------------------- */

void bookTicket(void)
{
    int trainId;
    printf("\n--- Book a Ticket ---\n");
    viewAllTrains();

    if (trainCount == 0)
        return;

    printf("\nEnter Train ID to book: ");
    scanf("%d", &trainId);
    clearInputBuffer();

    int idx = findTrainIndexById(trainId);
    if (idx == -1)
    {
        printf("Invalid Train ID.\n");
        return;
    }

    if (trains[idx].availableSeats <= 0)
    {
        printf("Sorry, no seats available on this train.\n");
        return;
    }

    if (bookingCount >= MAX_BOOKINGS)
    {
        printf("Booking system is full. Try again later.\n");
        return;
    }

    Booking b;
    printf("Passenger Name: ");
    readLine(b.passengerName, NAME_LEN);

    printf("Age: ");
    scanf("%d", &b.age);
    clearInputBuffer();

    printf("Gender (M/F/O): ");
    char genderInput[5];
    readLine(genderInput, 5);
    b.gender = (char)toupper((unsigned char)genderInput[0]);

    b.trainId = trainId;
    b.seatNumber = trains[idx].totalSeats - trains[idx].availableSeats + 1;
    b.pnr = nextPNR++;
    strcpy(b.status, "CONFIRMED");

    bookings[bookingCount++] = b;
    trains[idx].availableSeats--;

    saveBookings();
    saveTrains();

    printf("\nBooking Successful!\n");
    printf("Your PNR number is: %d\n", b.pnr);
    printf("Seat Number: %d\n", b.seatNumber);
    printf("Fare: %.2f\n", trains[idx].fare);
    printf("Please save your PNR to view or cancel this booking later.\n");
}

int findBookingIndexByPNR(int pnr)
{
    for (int i = 0; i < bookingCount; i++)
        if (bookings[i].pnr == pnr)
            return i;
    return -1;
}

void viewBookingByPNR(void)
{
    int pnr;
    printf("\n--- View Booking ---\n");
    printf("Enter PNR: ");
    scanf("%d", &pnr);
    clearInputBuffer();

    int idx = findBookingIndexByPNR(pnr);
    if (idx == -1)
    {
        printf("No booking found with that PNR.\n");
        return;
    }

    Booking *b = &bookings[idx];
    int tIdx = findTrainIndexById(b->trainId);

    printf("\nPNR            : %d\n", b->pnr);
    printf("Passenger Name : %s\n", b->passengerName);
    printf("Age / Gender   : %d / %c\n", b->age, b->gender);
    printf("Train          : %s (ID %d)\n",
           tIdx != -1 ? trains[tIdx].name : "Unknown", b->trainId);
    if (tIdx != -1)
        printf("Route          : %s -> %s\n", trains[tIdx].source, trains[tIdx].destination);
    printf("Seat Number    : %d\n", b->seatNumber);
    printf("Status         : %s\n", b->status);
}

void cancelTicket(void)
{
    int pnr;
    printf("\n--- Cancel Ticket ---\n");
    printf("Enter PNR: ");
    scanf("%d", &pnr);
    clearInputBuffer();

    int idx = findBookingIndexByPNR(pnr);
    if (idx == -1)
    {
        printf("No booking found with that PNR.\n");
        return;
    }

    if (strcmp(bookings[idx].status, "CANCELLED") == 0)
    {
        printf("This ticket is already cancelled.\n");
        return;
    }

    char confirm;
    printf("Cancel ticket for %s (Train ID %d)? (y/n): ",
           bookings[idx].passengerName, bookings[idx].trainId);
    scanf(" %c", &confirm);
    clearInputBuffer();

    if (tolower((unsigned char)confirm) != 'y')
    {
        printf("Cancellation aborted.\n");
        return;
    }

    strcpy(bookings[idx].status, "CANCELLED");

    int tIdx = findTrainIndexById(bookings[idx].trainId);
    if (tIdx != -1)
        trains[tIdx].availableSeats++;

    saveBookings();
    saveTrains();

    printf("Ticket cancelled successfully.\n");
}

/* ---------------------------- Admin: view all bookings ---------------------------- */

void viewAllBookings(void)
{
    printf("\n--- All Bookings ---\n");
    if (bookingCount == 0)
    {
        printf("No bookings yet.\n");
        return;
    }

    printf("%-6s %-20s %-5s %-4s %-8s %-6s %-10s\n",
           "PNR", "Passenger", "Age", "Sex", "TrainID", "Seat", "Status");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < bookingCount; i++)
    {
        Booking *b = &bookings[i];
        printf("%-6d %-20s %-5d %-4c %-8d %-6d %-10s\n",
               b->pnr, b->passengerName, b->age, b->gender,
               b->trainId, b->seatNumber, b->status);
    }
}

/* ---------------------------- Menus ---------------------------- */

int getMenuChoice(void)
{
    int choice;
    if (scanf("%d", &choice) != 1)
    {
        clearInputBuffer();
        return -1;
    }
    clearInputBuffer();
    return choice;
}

void adminMenu(void)
{
    int choice;
    do
    {
        printf("\n========== ADMIN MENU ==========\n");
        printf("1. Add Train\n");
        printf("2. View All Trains\n");
        printf("3. View All Bookings\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = getMenuChoice();

        switch (choice)
        {
        case 1:
            addTrain();
            break;
        case 2:
            viewAllTrains();
            break;
        case 3:
            viewAllBookings();
            break;
        case 4:
            printf("Returning to main menu...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
        if (choice != 4)
            pause_screen();
    } while (choice != 4);
}

void userMenu(void)
{
    int choice;
    do
    {
        printf("\n========== USER MENU ==========\n");
        printf("1. View All Trains\n");
        printf("2. Search Trains (Source -> Destination)\n");
        printf("3. Book a Ticket\n");
        printf("4. Cancel a Ticket (by PNR)\n");
        printf("5. View Booking Details (by PNR)\n");
        printf("6. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = getMenuChoice();

        switch (choice)
        {
        case 1:
            viewAllTrains();
            break;
        case 2:
            searchTrains();
            break;
        case 3:
            bookTicket();
            break;
        case 4:
            cancelTicket();
            break;
        case 5:
            viewBookingByPNR();
            break;
        case 6:
            printf("Returning to main menu...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
        if (choice != 6)
            pause_screen();
    } while (choice != 6);
}

void seedSampleData(void)
{
    /* Only seed if there is no existing train data, so re-running keeps user data */
    if (trainCount > 0)
        return;

    Train samples[3] = {
        {101, "Rajdhani Express", "Delhi", "Mumbai", 50, 50, 1500.00f},
        {102, "Shatabdi Express", "Lucknow", "Delhi", 40, 40, 800.00f},
        {103, "Duronto Express", "Kolkata", "Chennai", 60, 60, 1750.00f}};
    for (int i = 0; i < 3; i++)
        trains[trainCount++] = samples[i];

    saveTrains();
}

int mainMenu(void)
{
    int choice;
    printf("\n=========================================\n");
    printf("     TRAIN TICKET BOOKING SYSTEM\n");
    printf("=========================================\n");
    printf("1. Admin Login\n");
    printf("2. User / Passenger\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    choice = getMenuChoice();
    return choice;
}

/* ---------------------------- Main ---------------------------- */

int main(void)
{
    loadTrains();
    loadBookings();
    seedSampleData();

    int choice;
    do
    {
        choice = mainMenu();
        switch (choice)
        {
        case 1:
            adminMenu();
            break;
        case 2:
            userMenu();
            break;
        case 3:
            printf("\nThank you for using the Train Ticket Booking System!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}