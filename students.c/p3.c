#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee e;

    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &e.salary);

    printf("-------------------------\n");
    printf("Employee ID     : %d\n", e.id);
    printf("Employee Name   : %s\n", e.name);
    printf("Employee Salary : %.2f\n", e.salary);

    return 0;
}