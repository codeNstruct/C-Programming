#include<stdio.h>
#include<string.h>

struct student
{
    char name[40];
    int age;
    int marks;
};
struct student students[100];

int loadStudents(struct student students[])
{
    FILE *fp;
    int count = 0;

    fp = fopen("students.txt", "r");

    if(fp == NULL)
    {
        return 0;
    }

    while(count<100 && fscanf(fp, "%s", students[count].name) == 1 &&
          fscanf(fp, "%d", &students[count].age) == 1 &&
          fscanf(fp, "%d", &students[count].marks) == 1)
    {
        count++;
    }

    fclose(fp);

    return count;
}

void addStudent(struct student students[], int *count)
{
    FILE *fp;
    fp=fopen("students.txt","a");
    if(fp==NULL)
    {
        printf("File could not be opened!");
    }
    else
    {
        printf("Enter Student Details\n");
        printf("Name: ");
        scanf("%s",students[*count].name);
        printf("Age: ");
        scanf("%d",&students[*count].age);
        printf("Marks: ");
        scanf("%d",&students[*count].marks);  
        
        fprintf(fp, "%s\n", students[*count].name);
        fprintf(fp, "%d\n", students[*count].age);
        fprintf(fp, "%d\n", students[*count].marks);
        (*count)++;
        printf("Student data saved successfully!\n");
        fclose(fp);
    } 
}

void displayStudents(struct student students[],int count)
{
    printf("---------- STUDENT RECORDS ----------\n");
    for(int i=0; i<count; i++)
    {
        printf("\nStudent %d\n",i+1);
        printf("Name: %s\n",students[i].name);
        printf("Age: %d\n",students[i].age);
        printf("Marks: %d\n",students[i].marks);
    }
}

int searchStudent(struct student students[],int count)
{
    char searchName[40];    
    int found=0;
    printf("Enter student name to search:");
    scanf("%s",searchName);
    for(int i=0; i<count; i++)
    {
        if(strcmp(students[i].name, searchName)==0)
        {
            printf("Student Found!\n");
            printf("Name: %s\n",students[i].name);
            printf("Age: %d\n",students[i].age);
            printf("Marks: %d\n",students[i].marks);

            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Student not found!\n");
    }
    return found;
}

void findTopper(struct student students[],int count)
{
    int topper=0;
    if(count==0)
    {
        printf("\nNo students available\n");
    }
    else
    {
        for(int i=0; i<count; i++)
        {
            if(students[i].marks > students[topper].marks)
            {
                topper=i;
            }
        }
        printf("Topper is: %s\n", students[topper].name);
        printf("Age: %d\n", students[topper].age);
        printf("Marks: %d", students[topper].marks);
    }
}

void updateMarks(struct student students[],int count)
{
    char searchName[40];
    int newMarks;
    int found=0;
    printf("Enter student name to search:");
    scanf("%s",searchName);
    for(int i=0; i<count; i++)
    {
        if(strcmp(students[i].name, searchName)==0)
        {
            printf("Enter new marks: ");
            scanf("%d",&newMarks);

            students[i].marks=newMarks;
            found=1;
            FILE *fp;
            fp=fopen("students.txt","w");
            if(fp==NULL)
            {
                printf("File could not be opened!\n");
                
            }
            else
            {
                for(int j=0; j<count; j++)
                {
                    fprintf(fp, "%s\n", students[j].name);
                    fprintf(fp, "%d\n", students[j].age);
                    fprintf(fp, "%d\n", students[j].marks);
                }
                fclose(fp);
                printf("Marks updated successfully!\n");
            }
            break;
        }
    }    
    if(found==0)
    {
        printf("Student not found!\n");
    }
}

void deleteStudent(struct student students[],int *count)
{
    char deleteName[40];
    int found=0;
    printf("Enter student name to delete: ");
    scanf("%s",deleteName);
    for(int i=0; i<*count; i++)
    {
        if(strcmp(students[i].name, deleteName)==0)
        {
            for(int j=i; j<*count-1; j++)
            {
                students[j]=students[j+1];
            }
            (*count)--;
            found=1;
            FILE *fp;
            fp=fopen("students.txt","w");
            if(fp==NULL)
            {
                printf("File could not be opened!\n");
            }
            else
            {
                for(int k=0; k<*count; k++)
                {
                    fprintf(fp, "%s\n", students[k].name);
                    fprintf(fp, "%d\n", students[k].age);
                    fprintf(fp, "%d\n", students[k].marks);
                }
                fclose(fp);
            }
            printf("Student deleted successfully!\n");
            break;
        }
    }
    if(found==0)
    {
        printf("Student not found!\n");
    }
}

int main()
{
    int count;
    count=loadStudents(students);
    int choice=0;
    while(choice !=7)
    {
        printf("\n========== STUDENT FILE MANAGER ==========\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Find Topper\n");
        printf("5. Update student marks\n");
        printf("6. Delete student\n");
        printf("7. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(count>=100)
            {
                printf("Student limit reached!\n");
                break;
            }
            else
            {
                addStudent(students, &count);
            }
            break;

            case 2:
            displayStudents(students,count);
            break;

            case 3:
            searchStudent(students,count);
            break;

            case 4:
            findTopper(students,count);
            break;

            case 5:
            updateMarks(students,count);
            break;

            case 6:
            deleteStudent(students,&count);
            break;    

            case 7:
            printf("Good bye!");
            break;

            default:
            printf("Invalid Choice\n");
            break;
        }
    }
}
