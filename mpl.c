#include<stdio.h>
#include<string.h>
struct product
{
    int productID;
    char productName[30];
    float price;
    int stock;
};
struct product products[100];
void addProduct(struct product products[],int *count)
{
    FILE *fp;
    fp=fopen("Products.txt","a");
    if(fp==NULL)
    {
        printf("File could not be found!\n");
    }
    else
    {
        printf("Enter Product ID: ");
        scanf("%d",&products[*count].productID);
        getchar();
        printf("Enter Product Name: ");
        fgets(products[*count].productName,50,stdin);
        products[*count].productName[strcspn(products[*count].productName,"\n")]='\0';
        printf("Enter Product Price: ");
        scanf("%f",&products[*count].price);
        printf("Enter the stock available: ");
        scanf("%d",&products[*count].stock);
        
         
        fprintf(fp,"%d\n",products[*count].productID);
        fprintf(fp,"%s\n",products[*count].productName);
        fprintf(fp,"%.2f\n",products[*count].price);
        fprintf(fp,"%d\n",products[*count].stock);
        (*count)++;
        fclose(fp);
        printf("Product Added Successfully\n");
    }
}
int loadProduct(struct product products[])
{
    int count=0;
    FILE *fp;
    fp=fopen("Products.txt","r");
    if(fp==NULL)
    {
        return 0;
    }
    while(count < 100 && fscanf(fp, "%d", &products[count].productID)==1)
    {
        fgets(products[count].productName,50,fp);
        products[count].productName[strcspn(products[count].productName,"\n")]='\0';
        fscanf(fp, "%f", &products[count].price);
        fscanf(fp,"%d", &products[count].stock);
        count++;
    }
    fclose(fp);
    return count;
}
void displayProducts(struct product products[],int count)
{
    for(int i=0; i<count; i++)
    {
        printf("\nProduct %d:\n",i+1);
        printf("Product ID: %d\n",products[i].productID);
        printf("Product Name: %s\n",products[i].productName);
        printf("Price: %.2f\n",products[i].price);
        printf("Stock: %d\n",products[i].stock);

    }
}
void searchProduct(struct product products[],int count)
{
    int found=0;
    int searchId;
    printf("Enter Product ID to search: ");
    scanf("%d",&searchId);
    for(int i=0; i<count; i++)
    {
        if(searchId==products[i].productID)
        {
            printf("Product found!\n");
            printf("Product ID: %d\n",products[i].productID);
            printf("Product Name: %s\n",products[i].productName);
            printf("Price: %.2f\n",products[i].price);
            printf("Stock: %d\n",products[i].stock);
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Product not found!\n");
    }
}
void updateProduct(struct product products[],int count)
{
    int searchID;
    int found=0;
    printf("Enter Product ID to update: ");
    scanf("%d",&searchID);
    for(int i=0;i<count;i++)
    {
        if(searchID==products[i].productID)
        {
            printf("Product Found!\n");
            found=1;
            getchar();
            printf("Enter new Product Name: ");
            fgets(products[i].productName,50,stdin);
            products[i].productName[strcspn(products[i].productName,"\n")]='\0';
            printf("Enter new Price: ");
            scanf("%f",&products[i].price);
            printf("Enter new Stock: ");
            scanf("%d",&products[i].stock);
            
            FILE *fp;
            fp=fopen("Products.txt","w");
            if(fp==NULL)
            {
                printf("File could not be foun!\n");
            }
            else
            {
                for(int j=0; j<count; j++)
                {
                    fprintf(fp,"%d\n",products[j].productID);
                    fprintf(fp,"%s\n",products[j].productName);
                    fprintf(fp,"%.2f\n",products[j].price);
                    fprintf(fp,"%d\n",products[j].stock);
                }
                fclose(fp);
                printf("Updated Successfully!\n");
            }
            break;
        }
    }
    if(found==0)
    {
        printf("Product not found!\n");
    }
}
void deleteProduct(struct product products[],int *count)
{

    int found=0;
    int deleteID;
    printf("Enter Product ID to delete: ");
    scanf("%d",&deleteID);
    for(int i=0; i<*count; i++)
    {
        if(deleteID==products[i].productID)
        {
            for(int j=i; j<*count-1; j++)
            {
                products[j]=products[j+1];
            }
            (*count)--;
            found=1;
            FILE *fp;
            fp=fopen("Products.txt","w");
            if(fp==NULL)
            {
                printf("File could not be foun!\n");
            }
            else
            {
                for(int k=0; k<*count; k++)
                {
                    fprintf(fp,"%d\n",products[k].productID);
                    fprintf(fp,"%s\n",products[k].productName);
                    fprintf(fp,"%.2f\n",products[k].price);
                    fprintf(fp,"%d\n",products[k].stock);
                }
                fclose(fp);
                printf("Deleted Successfully!\n");
            }
            break;
        }
    }
    if(found==0)
    {
        printf("Product not found!\n");
    }
}
void generateBill(struct product products[],int count)
{
    int selectedpID;
    int quantity;
    float total;
    float grandTotal=0;
    char billNames[100][50];
    float billPrices[100];
    int billQuantities[100];
    float billTotals[100];
    int billCount=0;
    char choice;
    do{
        int found=0;
        printf("Enter Product ID: ");
        scanf("%d",&selectedpID);
        for(int i=0;i<count;i++)
        {
            if(selectedpID==products[i].productID)
            {
                found=1;
                printf("Enter Quantity: ");
                scanf("%d",&quantity);
                if(products[i].stock >= quantity)
                {
                    total=products[i].price*quantity;
                    strcpy(billNames[billCount],products[i].productName);
                    billPrices[billCount]=products[i].price;
                    billQuantities[billCount]=quantity;
                    billTotals[billCount]=total;
                    billCount++;
                    grandTotal+=total;
                    products[i].stock=products[i].stock-quantity;

                    FILE *fp;
                    fp=fopen("Products.txt","w");
                    if(fp==NULL)
                    {
                        printf("File could not be foun!\n");
                    }
                    else
                    {
                        for(int j=0; j<count; j++)
                        {
                            fprintf(fp,"%d\n",products[j].productID);
                            fprintf(fp,"%s\n",products[j].productName);
                            fprintf(fp,"%.2f\n",products[j].price);
                            fprintf(fp,"%d\n",products[j].stock);
                        }
                        fclose(fp);
                    }
                }
                else
                {
                    printf("Not enough Stock!\n");
                    printf("Available Stock: %d\n",products[i].stock);
                }
                break;
            }
        }   
        if(found==0)
        {
            printf("Product not found!\n");
        }
        printf("Add another Product?(Y/N)");
        scanf(" %c", &choice);
    }while(choice=='Y'|| choice=='y');
    printf("========== BILL ==========\n");
    printf("%-20s %-10s %-10s %10s\n", "Product Name", "Quantity", "Price", "Total");
    for(int i=0; i<billCount;i++)
    {
        
        printf("%-20s %-10d %-10.2f %10.2f\n",billNames[i],billQuantities[i],billPrices[i],billTotals[i]);
    }
    printf("--------------------------\n");
    printf("GRAND TOTAL: %.2f\n",grandTotal);
    printf("===========================\n");
}
int main()
{
    int choice;
    int count;
    count=loadProduct(products);
    do{
        printf("========== MINI STORE / BILLING SYSTEM ==========\n");
        printf("\n1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Generate Bill\n");
        printf("7. Exit\n");
        printf("\n==============================================\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(count>=100)
            {
                printf("File limit Reached!\n");
            }
            else
            {
                addProduct(products,&count);
            }
            break;

            case 2:
            displayProducts(products,count);
            break;

            case 3:
            searchProduct(products,count);
            break;

            case 4:
            updateProduct(products,count);
            break;

            case 5:
            deleteProduct(products,&count);
            break;

            case 6:
            generateBill(products,count);
            break;

            case 7:
            printf("Please visit again!\n");
            break;

            default:
            printf("Invalid choice!\n");
            break;
        }
    }while(choice!=7);
}