#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
    float tax;
    float net_salary;
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

    e.tax = e.salary * 0.10;
    e.net_salary = e.salary - e.tax;

    printf("\n----- Employee Details -----\n");
    printf("Employee ID     : %d\n", e.id);
    printf("Employee Name   : %s\n", e.name);
    printf("Employee Salary : %.2f\n", e.salary);
    printf("Income Tax (10%%): %.2f\n", e.tax);
    printf("Net Salary      : %.2f\n", e.net_salary);

    return 0;
}