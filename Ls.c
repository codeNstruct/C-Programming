#include<stdio.h>
int main()
{
    int arr[5];
    int key;
    int found=0;
    for(int i=0; i < 5; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d",&key);
    for(int i=0; i < 5; i++)
    {
        if(arr[i]==key)
        {
            printf("%d Found at index %d",key,i);
            found = 1;
            break;
        }        
    }
    if(found==0)
    {
        printf("Not found");
    }
    return 0;
}