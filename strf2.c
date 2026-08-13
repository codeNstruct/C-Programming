#include<stdio.h>
#include<string.h>
int main()
{
    char name[20];
    char pswd[20];
    printf("Enter Username: ");
    scanf("%s",name);
    printf("Enter the password: ");
    scanf("%s",pswd);
    if (strcmp(name, "Anusha") ==0 && strcmp(pswd, "Captain3") ==0)
    {
        printf("Login Suceesfull");
    }
    else{
        printf("Invalid Username and Password");
    }
    return 0;
    
}