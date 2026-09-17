#include <stdio.h>

int main() {
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("Addition        : %d\n",a+b);
    printf("Subtraction     : %d\n",a-b);
    printf("Multiplication  : %d\n",a*b);
    printf("Division        : %d\n",a/b);
    printf("Remainder       : %d",a%b);
    

    return 0;
}