#include <stdio.h>

#define MAX 100

typedef struct employee
{
    int emp_id;
    char emp_name[20];
    char emp_designation[20];
    float emp_salary;
}employee;

employee emp[MAX];
int count=0;

void saveToFile() {
    FILE *fp = fopen("employee.dat", "wb");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(emp, sizeof(employee), count, fp);

    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen("employee.dat", "rb");

    if (fp == NULL)
        return;

    fread(&count, sizeof(int), 1, fp);
    fread(emp, sizeof(employee), count, fp);

    fclose(fp);
}

void add_employee(){
    if (count == MAX) {
    printf("Employee database is full!!\n");
    return;
    }
    printf("Enter employee ID: ");
    scanf("%d", &emp[count].emp_id);
    for (int i = 0; i < count; i++) {
        if (emp[i].emp_id == emp[count].emp_id) {
            printf("Employee ID already exists!\n");
            return;
        }
    }
    printf("Enter employee name: ");
    scanf(" %19[^\n]", emp[count].emp_name);
    printf("Enter employee designation: ");
    scanf(" %19[^\n]", emp[count].emp_designation);
    printf("Enter employee salary: ");
    scanf("%f", &emp[count].emp_salary);
    count++;
    saveToFile();
    printf("Employee added successfully!!\n");
}

void display_employee(){
    if (count==0){
        printf("No employee record found!!\n");
        return;
    }
    printf("%-10s %-20s %-20s %-10s\n","Emp ID", "Emp Name", "Designation", "Salary");
    for (int i=0;i<count;i++){
        printf("%-10d %-20s %-20s %-10.2f\n",emp[i].emp_id,emp[i].emp_name,emp[i].emp_designation,emp[i].emp_salary);
    }
}

void search_employee(){
    if (count==0){
        printf("No employee record found!!\n");
        return;
    }
    int id,found=0;
    printf("Enter the employee id to search: ");
    scanf("%d", &id);
    for (int i=0;i<count;i++){
        if(emp[i].emp_id==id){
            printf("ID: %d\n",emp[i].emp_id);
            printf("Name: %s\n",emp[i].emp_name);
            printf("Designation: %s\n",emp[i].emp_designation);
            printf("Salary: %.2f\n",emp[i].emp_salary);
            found=1;
            break;
        }
    }
    if (found==0){
        printf("Employee not found!!\n");
    }
}

void delete_employee(){
    if (count==0){
        printf("No employee record found!!\n");
        return;
    }
    int id,found=0;
    printf("Enter the employee id to delete: ");
    scanf("%d", &id);
    for (int i=0;i<count;i++){
        if(emp[i].emp_id==id){
            found=1;
            for (int j=i;j<count-1;j++){
                emp[j]=emp[j+1];
            }
            count--;
            saveToFile();
            printf("Employee deleted succesfully!!\n");
            break;
        }
    }
    if (found==0){
        printf("Employee not found!!\n");
    }
}


int main(){

    loadFromFile();

    printf("===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n\n");

        int choice=0;

        while (choice!=5){
        printf("Enter the choice(1-5): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_employee();
            break;
        case 2:
            display_employee();
            break;
        case 3:
            search_employee();
            break;
        case 4:
            delete_employee();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!!\n");
            break;
        }
        if (choice!=5)
            printf("\nIs there anything else you would like to do?\n");
    }
    return 0;
}