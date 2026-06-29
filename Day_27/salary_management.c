#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct
{
    int id;
    char name[50];
    char designation[30];
    float basic, hra, da, pf, tax, net;
} Employee;

Employee emp[MAX];
int count = 0;

void calc(Employee *e)
{
    e->net = e->basic + e->hra + e->da - e->pf - e->tax;
}

void save()
{
    FILE *fp = fopen("salary.dat", "wb");
    if (!fp)
        return;
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(emp, sizeof(Employee), count, fp);
    fclose(fp);
}
void load()
{
    FILE *fp = fopen("salary.dat", "rb");
    if (!fp)
        return;
    fread(&count, sizeof(int), 1, fp);
    fread(emp, sizeof(Employee), count, fp);
    fclose(fp);
}
void add()
{
    printf("ID: ");
    scanf("%d", &emp[count].id);
    printf("Name: ");
    scanf(" %49[^\n]", emp[count].name);
    printf("Designation: ");
    scanf(" %29[^\n]", emp[count].designation);
    printf("Basic Salary: ");
    scanf("%f", &emp[count].basic);
    printf("HRA: ");
    scanf("%f", &emp[count].hra);
    printf("DA: ");
    scanf("%f", &emp[count].da);
    printf("PF: ");
    scanf("%f", &emp[count].pf);
    printf("Tax: ");
    scanf("%f", &emp[count].tax);
    calc(&emp[count]);
    count++;
    save();
}
int find(int id)
{
    for (int i = 0; i < count; i++)
        if (emp[i].id == id)
            return i;
    return -1;
}
void display()
{
    if (count == 0)
    {
        printf("No records\n");
        return;
    }
    printf("\nID\tName\tDesignation\tBasic\tNet\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%s\t%s\t%.2f\t%.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].basic, emp[i].net);
}
void search()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    int i = find(id);
    if (i == -1)
    {
        printf("Not found\n");
        return;
    }
    printf("Name:%s\nDesignation:%s\nNet Salary:%.2f\n", emp[i].name, emp[i].designation, emp[i].net);
}
void update()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    int i = find(id);
    if (i == -1)
    {
        printf("Not found\n");
        return;
    }
    printf("New Basic HRA DA PF Tax: ");
    scanf("%f%f%f%f%f", &emp[i].basic, &emp[i].hra, &emp[i].da, &emp[i].pf, &emp[i].tax);
    calc(&emp[i]);
    save();
}
void del()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    int i = find(id);
    if (i == -1)
    {
        printf("Not found\n");
        return;
    }
    for (int j = i; j < count - 1; j++)
        emp[j] = emp[j + 1];
    count--;
    save();
}
int main()
{
    load();
    int ch;
    do
    {
        printf("\n1.Add\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            update();
            break;
        case 5:
            del();
            break;
        case 6:
            save();
            printf("Thank you!\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 6);
    return 0;
}
