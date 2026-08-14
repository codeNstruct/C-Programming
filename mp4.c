#include<stdio.h>
#include<string.h>
int main()
{
    struct student
    {
        char name[30];
        int age;
        int marks;
    };
    struct student students[2];
    printf("========== STUDENT RECORD ==========\n");
    for(int i=0; i<2; i++)
    {
        printf("\nEnter Student %d\n",i+1);
        printf("Name: ");
        scanf("%s",students[i].name);
        printf("Age: ");
        scanf("%d",&students[i].age);
        printf("Marks: ");
        scanf("%d",&students[i].marks);
    }
    int choice=0;
    while(choice != 4)
    {
        printf("\n========== STUDENT RECORD SYSTEM ==========\n");
        printf("1. Display All Students\n");
        printf("2. Find Top Student\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("\n========================================\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\n---------- RECORD ----------\n");
            for(int i=0; i<2; i++)
            {
                printf("\n\nStudent %d details:\n",i+1);
                printf("Name: %s\n",students[i].name);
                printf("Age: %d\n",students[i].age);
                printf("Marks: %d",students[i].marks);
            }
            break;

            case 2:
            {
                int topstudent=0;
                for(int i=0; i<2; i++)
                {
                    if(students[i].marks > students[topstudent].marks)
                    {
                        topstudent=i;
                    }
                }
                printf("\n🏆Top Student\n");
                printf("Name: %s\n",students[topstudent].name);
                printf("Marks: %d\n",students[topstudent].marks);
            }
            break;

            case 3:
            {
                char searchName[35];
                int found=0;
                printf("Enter student name to search: ");
                scanf("%s",searchName);
                for(int i=0; i<2; i++)
                {
                    if(strcmp(searchName, students[i].name) ==0)
                    {
                        printf("\nStudent Found!\n");
                        printf("Name: %s\n",students[i].name);
                        printf("Age: %d\n",students[i].age);
                        printf("Marks: %d",students[i].marks);

                        found=1;
                        break;
                    }
                }
                if(found==0)
                {
                    printf("Student not found");
                }
            }
            break;

            case 4:
            printf("Exit");
            break;

            default:
            printf("Invalid choice!");
            break;

        }
    }
    return 0;
}       