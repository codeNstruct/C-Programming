#include<stdio.h>
#include<string.h>
struct account
{
    int accountNumber;
    char name[30];
    char phone[15];
    float balance;
};
struct account accounts[100];

void createAccount(struct account accounts[],int *count)
{
    FILE *fp;
    fp=fopen("Accounts.txt","a");
    if(fp==NULL)
    {
        printf("File could not be opened!\n");
    }
    else
    {
        printf("Enter Account number: ");
        scanf("%d", &accounts[*count].accountNumber);
        printf("Enter Name: ");
        scanf("%s", accounts[*count].name);
        printf("Enter Phone NUmber: ");
        scanf("%s", accounts[*count].phone);
        printf("Enter Initial balance: ");
        scanf("%f", &accounts[*count].balance);

        fprintf(fp, "%d\n", accounts[*count].accountNumber);
        fprintf(fp, "%s\n", accounts[*count].name);
        fprintf(fp, "%s\n", accounts[*count].phone);
        fprintf(fp, "%.2f\n", accounts[*count].balance);
        (*count)++;
        fclose(fp);
        printf("Account saved Successfully!\n");
    }
}

int loadAccounts(struct account accounts[])
{
    int count=0;
    FILE *fp;
    fp=fopen("Accounts.txt","r");
    if(fp==NULL)
    {
        return 0;
    }
    while(count < 100 && fscanf(fp, "%d", &accounts[count].accountNumber)==1 && fscanf(fp, "%s", accounts[count].name)==1 && fscanf(fp, "%s", accounts[count].phone)==1 && fscanf(fp, "%f", &accounts[count].balance)==1)
    {
        count++;
    }
    fclose(fp);
    return count;
}

void displayAccount(struct account accounts[],int count)
{
    printf("---------- ACCOUNT RECORS ----------\n");
    for(int i=0; i < count; i++)
    {
        printf("\nAccount %d\n",i+1);
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Phone: %s\n", accounts[i].phone);
        printf("Balance: %.2f\n", accounts[i].balance);
    }
}

void searchAccount(struct account accounts[],int count)
{
    char searchName[30];
    int found=0;
    printf("Enter Account holder's Name to search: ");
    scanf("%s", searchName);
    for(int i=0; i<count; i++)
    {
        if(strcmp(accounts[i].name, searchName)==0)
        {
            printf("Account found!\n");
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Phone: %s\n", accounts[i].phone);
            printf("Balance: %.2f\n", accounts[i].balance);
            
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Account not found!\n");
    }
}

void depositMoney(struct account accounts[],int count)
{
    float depositAmount;
    int accountNum;
    int found=0;
    printf("Enter the Account number: ");
    scanf("%d", &accountNum);
    for(int i=0; i<count; i++)
    {
        if(accounts[i].accountNumber== accountNum)
        {
            printf("Account found!\n");
            printf("Enter Amount to Deposit: ");
            scanf("%f", &depositAmount);
            if(depositAmount > 0)
            {
                accounts[i].balance += depositAmount;
                found=1;
                FILE *fp;
                fp=fopen("Accounts.txt","w");
                if(fp==NULL)
                {
                    printf("File could not be opened!\n");
                }
                else
                {
                    for(int j=0; j<count; j++)
                    {
                        fprintf(fp, "%d\n", accounts[j].accountNumber);
                        fprintf(fp, "%s\n", accounts[j].name);
                        fprintf(fp, "%s\n", accounts[j].phone);
                        fprintf(fp, "%.2f\n", accounts[j].balance);

                    }
                    fclose(fp);
                    printf("Deposit successful!\n");
                }
                break;
            }
            else
            {
                printf("Invalid Amount!\n");
            }
        }
    }
    if(found==0)
    {
        printf("Account not found!\n");
    }
}

void withdrawMoney(struct account accounts[],int count)
{
    int accountNum;
    float withdrawalAmount;
    int found=0;
    printf("Enter the Account number: ");
    scanf("%d", &accountNum);
    for(int i=0; i<count; i++)
    {
        if(accounts[i].accountNumber== accountNum)
        {
            printf("Account found!\n");
            found=1;
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &withdrawalAmount);
            if(withdrawalAmount <= accounts[i].balance && withdrawalAmount > 0)
            {
                accounts[i].balance -= withdrawalAmount;
                FILE *fp;
                fp=fopen("Accounts.txt","w");
                if(fp==NULL)
                {
                    printf("File could not be opened!\n");
                }
                else
                {
                    for(int j=0; j<count; j++)
                    {
                        fprintf(fp, "%d\n", accounts[j].accountNumber);
                        fprintf(fp, "%s\n", accounts[j].name);
                        fprintf(fp, "%s\n", accounts[j].phone);
                        fprintf(fp, "%.2f\n", accounts[j].balance);

                    }
                    fclose(fp);
                    printf("Withdrawal successful!\n");
                    break;
                }
            }
            else
            {
                printf("Invalid Amount!\n");
                break;
            }
        }
    }
    if(found==0)
    {
        printf("Account not found!\n");
    }
}

void checkBalance(struct account accounts[],int count)
{
    int accNum;
    int found=0;
    printf("Enter the Account Number: ");
    scanf("%d",&accNum);
    for(int i=0; i<count; i++)
    {
        if(accounts[i].accountNumber==accNum)
        {
            printf("Account Number: %d\n",accounts[i].accountNumber);
            printf("Name: %s\n",accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);

            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Account not found!\n");
    }
}
void deleteAccount(struct account accounts[],int *count)
{
    int accNum;
    int found=0;
    printf("Enter Account number to delete: ");
    scanf("%d",&accNum);
    for(int i=0; i<*count; i++)
    {
        if(accounts[i].accountNumber==accNum)
        {
            for(int j=i; j<*count-1; j++)
            {
                accounts[j]=accounts[j+1];
            }
            (*count)--;
            found=1;
            FILE *fp;
            fp=fopen("Accounts.txt","w");
            if(fp==NULL)
            {
                printf("File could not be found!\n");
            }
            else
            {
                for(int k=0;k<*count; k++)
                {
                    fprintf(fp,"%d\n",accounts[k].accountNumber);
                    fprintf(fp,"%s\n", accounts[k].name);
                    fprintf(fp,"%s\n", accounts[k].phone);
                    fprintf(fp,"%.2f\n", accounts[k].balance);
                }
                fclose(fp);
                printf("Account deleted Successfully!\n");
            }
            break;
        }
    }
    if(found==0)
    {
        printf("Account not found!\n");
    }
}
int main()
{
    int count;
    count=loadAccounts(accounts);
    int choice;
    while(choice != 8)
    {
        printf("========== BANK ACCOUNT MANAGEMENT SYSTEM ==========\n");
        printf("\n1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Check Balance\n");
        printf("7. Delete Account\n");
        printf("8. Exit\n");
        printf("\n==================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            if(count >= 100)
            {
                printf("Accounts limit Reached!\n");
                break;
            }
            else
            {
                createAccount(accounts,&count);
            }
            break;

            case 2:
            displayAccount(accounts,count);
            break;

            case 3:
            searchAccount(accounts,count);
            break;

            case 4:
            depositMoney(accounts,count);
            break;

            case 5:
            withdrawMoney(accounts,count);
            break;

            case 6:
            checkBalance(accounts,count);
            break;

            case 7:
            deleteAccount(accounts,&count);
            break;

            case 8:
            printf("Thank You.");
            break;

            default:
            printf("Invalid Choice:");
            break;
        }
    }
    return 0;
}