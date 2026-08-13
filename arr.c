#include<stdio.h>
int main()
{
    int arr[5];
    for (int i=0; i < 5; i++)
    {
        printf("Enter elements %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Entered elements are: ");
    for(int i=0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    int largest=arr[0];
    for(int i=0; i < 5; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }
        printf("\nLargest = %d",largest);
        return 0;
}