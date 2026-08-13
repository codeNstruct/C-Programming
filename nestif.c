#include<stdio.h>
int main()
{
    int age;
    int haveID;
    printf("Enter your age: \n");
    scanf("%d",&age);
    printf("Have an ID?(Yes=1/No=0): \n");
    scanf("%d",&haveID);
    if (age >= 18)
    {
        if(haveID == 1)
        {
             printf("Entry Allowed");
        }
        else
        {
             printf("ID Required");
        }
    }
    else
    {
        printf("Underage");
    }
    return 0;
}