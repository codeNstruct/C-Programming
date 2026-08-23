#include<stdio.h>
int main()
{
    FILE *fp;
    struct student
    {
        char name[40];
        int age;
        int marks;
    };
    struct student students[3];
    fp=fopen("students.txt","w");
    if(fp==NULL)
    {
        printf("File could not be opened!");
    }
    else
    {
        for(int i=0; i<3; i++)
        {
            printf("Enter Student %d Details\n",i+1);
            printf("Name: ");
            scanf("%s",students[i].name);
            printf("Age: ");
            scanf("%d",&students[i].age);
            printf("Marks: ");
            scanf("%d",&students[i].marks);
        }
        for(int i=0; i<3; i++)    
        {
            fprintf(fp, "%s\n", students[i].name);
            fprintf(fp, "%d\n", students[i].age);
            fprintf(fp, "%d\n", students[i].marks);
        }
        printf("Student data saved successfully!\n");
        fclose(fp);
    }   
    return 0;
}