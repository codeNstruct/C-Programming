#include<stdio.h>
#include<string.h>

struct contact
{
    char name[50];
    char phone[15];
    char email[30];
};
struct contact contacts[100];

void addContact(struct contact contacts[], int *count)
{
    FILE *fp;
    fp=fopen("contacts.txt", "a");
    if(fp==NULL)
    {
        printf("File could not be opened!\n");
    }
    else
    {
        printf("Enter Contact Name: ");
        scanf("%s", contacts[*count].name);
        printf("Enter Phone Number: ");
        scanf("%s", contacts[*count].phone);
        printf("Enter Email: ");
        scanf("%s", contacts[*count].email);

        fprintf(fp, "%s\n", contacts[*count].name);
        fprintf(fp, "%s\n", contacts[*count].phone);
        fprintf(fp, "%s\n", contacts[*count].email);
        (*count)++;
        printf("Contact saved Successfully!\n");
        fclose(fp);
    }
}

int loadContacts(struct contact contacts[])
{
    int count=0;
    FILE *fp;
    fp=fopen("contacts.txt","r");
    if(fp==NULL)
    {
        return 0;
    }
    while(count<100 && fscanf(fp, "%s", contacts[count].name)==1 && fscanf(fp, "%s", contacts[count].phone)==1 && fscanf(fp, "%s", contacts[count].email)==1)
    {
        count++;
    }
    fclose(fp);
    return count;
}

void displayContacts(struct contact contacts[],int count)
{
    printf("\n----------- CONTACTS RECORDS ------------\n");
    for(int i=0; i<count; i++)
    {
        printf("\nContact %d\n",i+1);
        printf("Name: %s\n",contacts[i].name);
        printf("Phone: %s\n",contacts[i].phone);
        printf("Email: %s\n",contacts[i].email);
    }
}

int searchContact(struct contact contacts[],int count)
{
    int found=0;
    char searchName[40];
    printf("Enter Contact name to search: ");
    scanf("%s", searchName);
    for(int i=0; i<count; i++)
    {
        if(strcmp(contacts[i].name, searchName)==0)
        {
            printf("Contact found\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n",contacts[i].phone);
            printf("Email: %s\n",contacts[i].email);

            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Contact not found!\n");
    }
    return found;
}

void updateContact(struct contact contacts[],int count)
{
    char searchName[40];
    char newPhone[15];
    char newEmail[30];
    int found=0;
    printf("Enter Contact name to Update: ");
    scanf("%s", searchName);
    for(int i=0; i<count; i++)
    {
        if(strcmp(contacts[i].name, searchName)==0)
        {
            printf("Enter new Phone number: ");
            scanf("%s",newPhone);
            strcpy(contacts[i].phone, newPhone);
            printf("Enter new Email: ");
            scanf("%s", newEmail);
            strcpy(contacts[i].email, newEmail);
            found=1;
            FILE *fp;
            fp=fopen("contacts.txt", "w");
            if(fp==NULL)
            {
                printf("File could not be opened!\n");
            }
            else
            {
                for(int j=0; j<count; j++)
                {
                    fprintf(fp,"%s\n",contacts[j].name);
                    fprintf(fp, "%s\n",contacts[j].phone);
                    fprintf(fp,"%s\n",contacts[j].email);
                }
                fclose(fp);
            }
            printf("Contact details updated successfully!\n");
            break;
        }
    }
    if(found==0)
    {
        printf("Contact not found!\n");
    }
}

void deleteContact(struct contact contacts[],int *count)
{
    char deleteName[40];
    int found=0;
    printf("Enter name to delete: ");
    scanf("%s", deleteName);
    for(int i=0; i<*count; i++)
    {
        if(strcmp(contacts[i].name, deleteName)==0)
        {
            for(int j=i; j<*count-1;j++)
            {
                contacts[j]=contacts[j+1];
            }
            (*count)--;
            found=1;
            FILE *fp;
            fp=fopen("contacts.txt","w");
            if(fp==NULL)
            {
                printf("File could not be opened!\n");
            }
            else
            {
                for(int k=0; k<*count; k++)
                {
                    fprintf(fp, "%s\n", contacts[k].name);
                    fprintf(fp,"%s\n", contacts[k].phone);
                    fprintf(fp,"%s\n", contacts[k].email);
                }
                fclose(fp);
            }
            printf("Deleted Successfully!\n");
            break;
        }
    }
    if(found==0)
    {
        printf("Contact not found!\n");
    }
}
int main()
{
    int count;
    count=loadContacts(contacts);
    int choice=0;
    while(choice !=6)
    {
        printf("\n========== CONTACT MANAGER ==========\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            if(count >=100)
            {
                printf("File Limit Reached!\n");
            }
            else
            {
                addContact(contacts,&count);
            }
            break;

            case 2:
            displayContacts(contacts,count);
            break;

            case 3:
            searchContact(contacts,count);
            break;

            case 4:
            updateContact(contacts,count);
            break;

            case 5:
            deleteContact(contacts,&count);
            break;

            case 6:
            printf("Good bye!\n");
            break;

            default:
            printf("Invalid Choice.\n");
            break;
        }
    }
    return 0;
}