#include<stdio.h>
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int multi(int a, int b)
{
    return a * b;
}
float div(int a, int b)
{
    return (float)a / b;
}
int main()
{
    int a,b,choice;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    printf("\n=======CALCULATOR=======\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");
    printf("==========================");
    printf("\nEnter your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\nAddition=%d",add(a,b));
        break;
        case 2:
        printf("\nSubtraction=%d",sub(a,b));
        break;
        case 3:
        printf("\nMultiplication=%d\n",multi(a,b));
        break;
        case 4:
        if (b != 0)
    {
        printf("\nDivision=%.2f",div(a,b));
    }
    else{
        printf("\nCannot divide by zero!");
    }
        break;
        default:
        printf("\nInvalid Choice");

    }
    return 0;
}