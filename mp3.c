#include<stdio.h>
int main()
{
    int marks[5];
    int sum=0;
    float average;

    for(int i=0; i<5; i++)
    {
        printf("Enter mark %d: ",i+1);
        scanf("%d",&marks[i]);
        sum=sum+marks[i];
    }
    int choice=0;
    while(choice < 6)
    {
        printf("\n========== STUDENT MARKS ==========");
        printf("\n1. Display Marks\n");
        printf("2. Calculate Total\n");
        printf("3. Calculate average\n");
        printf("4. Find Highest\n");
        printf("5. Find Lowest\n");
        printf("6. Exit\n");
        printf("===================================");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Marks: ");
            for(int i=0; i<5 ;i++)
            {
                printf("%d ",marks[i]);
            }
            break;

            case 2:
            printf("Sum: %d",sum);
            break;

            case 3:
            average=(float)sum/5;
            printf("Average: %.2f",average);
            break;

            case 4:
            {
                int highest=marks[0];
                for(int i=0; i<5; i++)
                {
                    if(marks[i]>highest)
                    {
                        highest=marks[i];
                    }
                }
                printf("Highest marks: %d",highest);
                break;
            }
        
            case 5:
            {
                int lowest=marks[0];
                for(int i=0;i<5; i++)
                {
                    if(marks[i]<lowest)
                    {
                        lowest=marks[i];
                    }
                }
                printf("Lowest marks: %d",lowest);
                break;
            }

            case 6:
            printf("Exit");
            break;

            default:
            printf("Invalid choice!");
            break;
        }
    }
    return 0;   
}