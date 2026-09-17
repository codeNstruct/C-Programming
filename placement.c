#include<stdio.h>
int main()
{
    int age;
    printf("Enter your age: ");
    scanf("%d",&age);
    if (age >= 18 && age <= 25)
    {
        printf("Eligible for Placement");
    }
    else
    {
        printf("Not Eligible");
    }
    return 0;
}