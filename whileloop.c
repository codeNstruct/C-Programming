#include<stdio.h>
int main()
{
    int i = 1,n;
    int fact = 1;
    printf("Enter a number: ");
    scanf("%d",&n);
    while (i <= n)
    {
        fact = fact * i;
        i++;
    }
    printf("Fctorial of a number is : %d",fact);
    return 0;
}