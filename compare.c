#include<stdio.h>
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    if (num > 0)
    {
        printf("Positive number\n");
    }
    else if (num < 0)
    {
        printf("Negative Number\n");
    }
    else
    {
        printf("Zero");
    }
    return 0;
}