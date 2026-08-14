#include<stdio.h>
void welcome()
{
    //printf("========== BANK ACCOUNT ==========\n");
    printf("Welcome to the Bank!\n");
}

void showBalance(int balance)
{
    printf("Current balance: Rs.%d",balance);
}

int deposit(int balance,int amount)
{
    if(amount <= balance && amount > 0)
    {
        balance=balance+amount;
        printf("Deposit Successful!\n");
    }
    else{
        printf("Invalid amount!\n");
    }
    return balance;
}

int withdrawal(int balance,int amount)
{
    if(amount <= balance && amount > 0)
    {
        balance=balance-amount;
        printf("Withdrawal Successful!\n");
    }
    else{
        printf("Invalid amount!\n");
    }
    return balance;
}
int main()
{
    int balance=50000;
    int amount;
    int choice=0;
    welcome();
    while(choice != 4)
    {
        printf("\n========== BANK ACCOUNT ==========\n");
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("==================================\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            showBalance(balance);
            break;

            case 2:
            printf("\nEnter the amount to deposit: ");
            scanf("%d",&amount);
            balance=deposit(balance,amount);
            showBalance(balance);
            break;

            case 3:
            printf("\nEnter the amount to Withdrawal: ");
            scanf("%d",&amount);
            balance=withdrawal(balance,amount);
            showBalance(balance);
            break;

            case 4:
            printf("Thank you.\nVisit us again!");
            break;

            default:
            printf("Invalid choice!");
            break;

        }
    }
    return 0;
}