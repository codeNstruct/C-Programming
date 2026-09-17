#include<stdio.h>
#include<string.h>
struct book
{
    int bookID;
    char bookName[50];
    char author[30];
    float price;
    char available;
};
struct book books[100];

void addBook(struct book books[], int *count)
{
    FILE *fp;
    fp=fopen("Books.txt","a");
    if(fp==NULL)
    {
        printf("File could not be found!\n");
    }
    else
    {
        printf("Enter the book ID: ");
        scanf("%d",&books[*count].bookID);
        getchar();
        printf("Enter the book name: ");
        fgets(books[*count].bookName,50,stdin);
        books[*count].bookName[strcspn(books[*count].bookName,"\n")]='\0';
        printf("Enter the book Author: ");
        fgets(books[*count].author,30,stdin);
        books[*count].author[strcspn(books[*count].author,"\n")]='\0';
        printf("Enter the book price: ");
        scanf("%f",&books[*count].price);
        books[*count].available='A';

        fprintf(fp, "%d\n",books[*count].bookID);
        fprintf(fp, "%s\n",books[*count].bookName);
        fprintf(fp, "%s\n",books[*count].author);
        fprintf(fp, "%.2f\n",books[*count].price);
        fprintf(fp, "%c\n",books[*count].available);
        (*count)++;
        fclose(fp);
        printf("Book added Successfully!\n");
    }
}
int loadbooks(struct book books[])
{
    int count=0;
    FILE *fp;
    fp=fopen("Books.txt","r");
    if(fp==NULL)
    {
        return 0;
    }
    while(count < 100 && fscanf(fp, "%d", &books[count].bookID)==1)
    {
        fgets(books[count].bookName,50,fp);
        books[count].bookName[strcspn(books[count].bookName, "\n")]='\0';
        fgets(books[count].author,30,fp);
        books[count].author[strcspn(books[count].author, "\n")]='\0'; 
        fscanf(fp,"%f", &books[count].price);
        fscanf(fp, " %c", &books[count].available);
        count++;
    }
    fclose(fp);
    return count;
}
void displaybooks(struct book books[],int count)
{
    printf("----- BOOK RECORDS -----\n");
    for(int i=0; i<count; i++)
    {
        printf("Book %d\n",i+1);
        printf("Book ID: %d\n", books[i].bookID);
        printf("Book Name: %s\n", books[i].bookName);
        printf("Book Author: %s\n", books[i].author);
        printf("Book Price: %.2f\n", books[i].price);
        if(books[i].available=='A')
        {
            printf("Availability:Available\n");
        }
        else
        {
            printf("Availability: Issued\n");
        }
    }
}
void searchBook(struct book books[],int count)
{
    int searchID;
    int found=0;
    printf("Enter Book ID to serach: ");
    scanf("%d", &searchID);
    for(int i=0; i<count;i++)
    {
        if(searchID==books[i].bookID)
        {
            printf("Book Found!\n");
            printf("Book ID: %d\n",books[i].bookID);
            printf("Book Name: %s\n", books[i].bookName);
            printf("Book Author: %s\n", books[i].author);
            printf("Book Price: %.2f\n", books[i].price);
            if(books[i].available=='A')
            {
                printf("Availability: Available");
            }
            else
            {
                printf("Availability: Issued");
            }

            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Book not found!\n");
    }
}
void issueBooks(struct book books[], int count)
{
    int found=0;
    int issueID;
    printf("Enter Book ID to issue: ");
    scanf("%d",&issueID);
    for(int i=0;i<count;i++)
    {
        if(issueID==books[i].bookID)
        {
            printf("Book Found!\n");
            found=1;
            if(books[i].available=='A')
            {
                printf("Yes it is available.\n");
                books[i].available='I';
                FILE *fp;
                fp=fopen("Books.txt","w");
                if(fp==NULL)
                {
                    printf("File could not be found!\n");
                }
                else
                {
                    for(int j=0;j<count;j++)
                    {
                        fprintf(fp,"%d\n",books[j].bookID);
                        fprintf(fp,"%s\n",books[j].bookName);
                        fprintf(fp,"%s\n",books[j].author);
                        fprintf(fp,"%.2f\n",books[j].price);
                        fprintf(fp,"%c\n",books[j].available);
                    }
                    fclose(fp);
                    printf("Book issued successfully!\n");
                }
                break;
            }
            else
            {
                printf("Already issued!\n");
            }
        }
    }
    if(found==0)
    {
        printf("Book not found!\n");
    }
}
void returnBooks(struct book books[],int count)
{
    int found=0;
    int returnbID;
    printf("Enter Book ID of returning book: ");
    scanf("%d",&returnbID);
    for(int i=0;i<count;i++)
    {
        if(returnbID==books[i].bookID)
        {
            printf("Book Found!\n");
            found=1;
            if(books[i].available=='I')
            {
                printf("It was issued.\n");
                books[i].available='A';
                FILE *fp;
                fp=fopen("Books.txt","w");
                if(fp==NULL)
                {
                    printf("File could not be found!\n");
                }
                else
                {
                    for(int j=0;j<count;j++)
                    {
                        fprintf(fp,"%d\n",books[j].bookID);
                        fprintf(fp,"%s\n",books[j].bookName);
                        fprintf(fp,"%s\n",books[j].author);
                        fprintf(fp,"%.2f\n",books[j].price);
                        fprintf(fp,"%c\n",books[j].available);
                    }
                    fclose(fp);
                    printf("Book Returned successfully!\n");
                }
                break;
            }
            else
            {
                printf("Already available!\n");
            }
        }
    }
    if(found==0)
    {
        printf("Book not found!\n");
    }
}
void updateBooks(struct book books[],int count)
{
    int found=0;
    int updatebID;
    printf("Enter Book ID to update: ");
    scanf("%d",&updatebID);
    getchar();
    for(int i=0;i<count;i++)
    {
        if(updatebID==books[i].bookID)
        {
            printf("Book Found!\n");
            found=1;
            printf("Enter new Book Name: ");
            fgets(books[i].bookName,50,stdin);
            books[i].bookName[strcspn(books[i].bookName,"\n")]='\0';
            printf("Enter the book Author: ");
            fgets(books[i].author,30,stdin);
            books[i].author[strcspn(books[i].author,"\n")]='\0';
            printf("Enter the new Price: ");
            scanf("%f",&books[i].price);
            FILE *fp;
            fp=fopen("Books.txt","w");
            if(fp==NULL)
            {
                printf("File could not be found!\n");
            }
            else
            {
                for(int j=0;j<count;j++)
                {
                    fprintf(fp,"%d\n",books[j].bookID);
                    fprintf(fp,"%s\n",books[j].bookName);
                    fprintf(fp,"%s\n",books[j].author);
                    fprintf(fp,"%.2f\n",books[j].price);
                    fprintf(fp,"%c\n",books[j].available);
                }
                fclose(fp);
                printf("Book Updated successfully!\n");
            }
            break;
        } 
    }
    if(found==0)
    {
        printf("Book not found!\n");
    }    
}
void deleteBooks(struct book books[],int *count)
{
    int found=0;
    int deletebID;
    printf("Enter Book ID to delete: ");
    scanf("%d",&deletebID);
    for(int i=0; i<*count; i++)
    {
        if(books[i].bookID==deletebID)
        {
            for(int j=i; j<*count-1; j++)
            {
                books[j]=books[j+1];
            }
            (*count)--;
            found=1;
            FILE *fp;
            fp=fopen("Books.txt","w");
            if(fp==NULL)
            {
                printf("File could not be found!\n");
            }
            else
            {
                for(int k=0;k<*count; k++)
                {
                    fprintf(fp,"%d\n",books[k].bookID);
                    fprintf(fp,"%s\n",books[k].bookName);
                    fprintf(fp,"%s\n",books[k].author);
                    fprintf(fp,"%.2f\n",books[k].price);
                    fprintf(fp,"%c\n",books[k].available);
                }
                fclose(fp);
                printf("Book deleted Successfully!\n");
            }
            break;
        }
    }
    if(found==0)
    {
        printf("Book not found!\n");
    }
}
void displayAvailablebooks(struct book books[],int count)
{
    for(int i=0;i<count;i++)
    {
        if(books[i].available=='A')
        {
            printf("----- AVAILABLE BOOKS -----\n");
            printf("Book ID: %d\n",books[i].bookID);
            printf("Book Name: %s\n",books[i].bookName);
            printf("Book Author: %s\n",books[i].author);
            printf("Book Price: %.2f\n",books[i].price);
        }
    }
}
void displayIssuedbooks(struct book books[],int count)
{
    for(int i=0;i<count;i++)
    {
        if(books[i].available=='I')
        {
            printf("----- ISSUED BOOKS -----\n");
            printf("Book ID: %d\n",books[i].bookID);
            printf("Book Name: %s\n",books[i].bookName);
            printf("Book Author: %s\n",books[i].author);
            printf("Book Price: %.2f\n",books[i].price);
        }
    }
}
int main()
{
    int choice;
    int count=loadbooks(books);
    do
    {
        printf("\n========= LIBRARY MANAGEMENT SYSTEM ===========\n");
        printf("\n1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Issue Book\n");
        printf("7. Return Book\n");
        printf("8. Available Books\n");
        printf("9. Issued Books\n");
        printf("10. Exit\n");
        printf("==============================================\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(count >= 100)
            {
                printf("File limit Reached!\n");
            }
            else
            {
                addBook(books,&count);
            }
            break;

            case 2:
            displaybooks(books,count);
            break;

            case 3:
            searchBook(books,count);
            break;

            case 4:
            updateBooks(books,count);            
            break;
            case 5:
            deleteBooks(books,&count);
            break;
            case 6:
            issueBooks(books,count);
            break;
            case 7:
            returnBooks(books,count);
            break;
            case 8:
            displayAvailablebooks(books,count);
            break;
            case 9:
            displayIssuedbooks(books,count);
            break;
            case 10:
            printf("Exit");
            break;
            default:
            printf("Invalid choice");
            break;
        }
    } while (choice != 8);
    return 0;
}