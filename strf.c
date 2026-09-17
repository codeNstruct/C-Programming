#include<stdio.h>
#include<string.h>
int main()
{
    char name1[20]="Anusha";
    char name2[20];
    
    strcpy(name2,name1);
    printf("Orginal: %s\n",name1);
    printf("Copied: %s",name2);

    strcpy(name2,"Captain");
    printf("\nAfter Inserting new value to name2:\n ");
    printf("Orginal: %s\n",name2);
    printf("Copied: %s",name2);
    return 0;
}