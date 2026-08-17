#include<stdio.h>

struct Employee
{
    int id;
    char name[40];
    int salary;
    int bonus;
};
struct Employee employees[3];

int calculateTotalSalary(int salary, int bonus)
{
    salary=salary+bonus;
    return salary;

}

int main()
{
    int totalsalary;
    int choice=0;
    for(int i=0; i<3; i++)
    {
        printf("Enter Employee %d details\n",i+1);
        printf("Enter Employee ID: ");
        scanf("%d",&employees[i].id);
        printf("Enter Employee Name: ");
        scanf("%s",&employees[i].name);
        printf("Enter Employee Basic salary: ");
        scanf("%d",&employees[i].salary);
        printf("Enter bonus: ");
        scanf("%d",&employees[i].bonus);
    }
    while(choice!=5)
    {
        printf("=========== EMPLOYEE PAYROLL ==========\n");
        printf("1. Display All Employees\n");
        printf("2. Find Highest Paid Employee\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee Salary\n");
        printf("5. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            //Display
            for(int i=0; i<3; i++)
            {
                totalsalary=calculateTotalSalary(employees[i].salary,employees[i].bonus);
                printf("Employee %d\n",i+1);
                printf("ID: %d\n",employees[i].id);
                printf("Name: %s\n",employees[i].name);
                printf("Basic Salary: %d\n",employees[i].salary);
                printf("Bonus: %d\n",employees[i].bonus);
                printf("Total Salary: %d\n",totalsalary);
            }
            break;

            case 2:
            //Highest-Paid Employee
            {
                int highestEmployee = 0;
                for(int i = 1; i < 3; i++)
                {
                    int currentTotal = calculateTotalSalary(employees[i].salary,employees[i].bonus);
                    int highestTotal = calculateTotalSalary(employees[highestEmployee].salary,employees[highestEmployee].bonus);
                    if(currentTotal > highestTotal)
                    {
                        highestEmployee = i;
                    }
                }
                int highestTotal = calculateTotalSalary(employees[highestEmployee].salary,employees[highestEmployee].bonus);
                printf("\nHighest Paid Employee\n");
                printf("ID: %d\n", employees[highestEmployee].id);
                printf("Name: %s\n", employees[highestEmployee].name);
                printf("Basic Salary: %d\n", employees[highestEmployee].salary);
                printf("Bonus: %d\n", employees[highestEmployee].bonus);
                printf("Total Salary: %d\n", highestTotal);
            }
            break;

            case 3:
            {
                int serachId;
                int found=0;
                printf("Enter employee ID to search: ");
                scanf("%d",&serachId);
                for(int i=0; i<3; i++)
                {
                    if(employees[i].id == serachId)
                    {
                        int employeeTotal=calculateTotalSalary(employees[i].salary,employees[i].bonus);
                        printf("Found the Employee!\n");
                        printf("ID: %d\n",employees[i].id);
                        printf("Name: %s\n",employees[i].name);
                        printf("Basic Salary: %d\n",employees[i].salary);
                        printf("Bonus: %d\n",employees[i].bonus);
                        printf("Total Salary: %d\n",employeeTotal);

                        found=1;
                        break;
                    }
                }
                if(found==0)
                {
                    printf("Employee not found!\n");
                }
            }
            break;

            case 4:
            {
                int newSalary;
                int searchID;
                int found=0;
                printf("Enter the Employee ID: ");
                scanf("%d",&searchID);
                for(int i=0; i<3; i++)
                {
                    if(employees[i].id==searchID)
                    {
                        printf("Enter new basic salary: ");
                        scanf("%d",&newSalary);
                        printf("Old salary: %d\n",employees[i].salary);
                        employees[i].salary=newSalary;
                        printf("New salary: %d\n",employees[i].salary);

                        found=1;
                        break;
                    }
                }
                if(found==0)
                {
                    printf("Employee not found!\n");
                }

            }
            break;

            case 5:
            printf("Exit");
            break;

            default:
            printf("Invalid Choice");
            break;
        }
    }
    return 0;
}