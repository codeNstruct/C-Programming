#include<stdio.h>
#include<string.h>
int main()
{
    char username[30];
    char password[30];
    printf("========== LOGIN ==========\n");
    printf("Enter Username: ");
    scanf("%s",username);
    printf("Enter Password: ");
    scanf("%s",password);
    if (strcmp(username, "Anusha")==0 && strcmp(password, "captain123") ==0)
    {
        printf("Login successful");
    }
    else{
        printf("Invalid Username or Password");
    }
    return 0;
}