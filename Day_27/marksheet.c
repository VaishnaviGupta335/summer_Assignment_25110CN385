#include <stdio.h>

typedef struct student_marksheet
{
    int rollNo;
    char name[20];
    float marks1,marks2,marks3;
    float total, percentage;
    char grade;
} marksheet;

int main(){
    marksheet st[5];
    for (int i=0;i<5;i++){
        printf("Enter roll no: ");
        scanf("%d", &st[i].rollNo);
        printf("Enter name: ");
        scanf("%s", &st[i].name);
        printf("Enter marks1, marks2, marks3: ");
        scanf("%f %f %f", &st[i].marks1,&st[i].marks2,&st[i].marks3);
        st[i].total=st[i].marks1+st[i].marks2+st[i].marks3;
        st[i].percentage=st[i].total/3;
        if (st[i].percentage>=90)
            st[i].grade='A';
        else if (st[i].percentage>=75)
            st[i].grade='B';
        else if (st[i].percentage>=60)
            st[i].grade='C';
        else if (st[i].percentage>=33)
            st[i].grade='D';
        else
            st[i].grade='F';
    
    }
    for(int i=0;i<5;i++){
        printf("Roll no: %d\n",st[i].rollNo);
        printf("Name: %s\n",st[i].name);
        printf("Marks1: %.2f\n",st[i].marks1);
        printf("Marks2: %.2f\n",st[i].marks2);
        printf("Marks2: %.2f\n",st[i].marks3);
        printf("Total marks: %.2f\n",st[i].total);
        printf("Percentage: %.2f\n",st[i].percentage);
        printf("Grade: %c\n", st[i].grade);
        printf("\n");
    }
    return 0;
}