#include<stdio.h>
int main()
{
    char name[20];
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Welcome, %s!\n",name);
    printf("Have a great day, %s!",name);
    return 0;
}