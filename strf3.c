#include<stdio.h>
#include<string.h>
int main()
{
    char first[30];
    char second[20];
    printf("Enter first word: ");
    scanf("%s",first);
    printf("Enter second word: ");
    scanf("%s",second);
    strcat(first, " ");
    strcat(first, second);
    printf("Result: %s",first);
    return 0;
}