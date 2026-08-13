#include<stdio.h>
int main()
{
    int choice=0;
    int balance=50000;
    int amount;
    while(choice != 4)
    {
        printf("\n========== ATM ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("=========================\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Current Balance: %d",balance);
            break;

            case 2:
            printf("Enter deposit amount: ");
            scanf("%d",&amount);
            if(amount > 0)
            {
                balance=balance+amount;
                printf("Deposit Successful!\n");
                printf("Current Balance: %d", balance);
            }
            else{
                printf("Invalid amount!");
            }
            break;

            case 3:
            printf("Enter withdrawal amount: ");
            scanf("%d",&amount);
            if(amount <= balance && amount > 0)
            {
                balance=balance-amount;
                printf("Withdrawal Successful!\n");
                printf("Current balance: %d", balance);
            }
            else{
                printf("Invalid amount!\n");
                printf("Current balance: %d", balance);
            }
            break;

            case 4:
            printf("Thank you for using the ATM!");
            break;

            default:
            printf("Invalid choice");
            break;
        }
    }    
    return 0;
}