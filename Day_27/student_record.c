#include <stdio.h>

typedef struct student_record
{
    int student_rollno;
    char student_name[20];
    float student_percentage;
} student;

int main()
{
    student stu[5]={
        {101, "Aman", 85.5},
        {102, "Priya", 91.0},
        {103, "Rohit", 78.5},
        {104, "Neha", 88.0},
        {105, "Karan", 82.5}
    };

    printf("Student Records:\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Roll No: %d\n", stu[i].student_rollno);
        printf("Name: %s\n", stu[i].student_name);
        printf("Percentage: %.1f\n\n", stu[i].student_percentage);
    }
    return 0;
}