#include<stdio.h>
int main()
{
    int arr[5];
    int sum=0,n;
    float average;
    for(int i=0; i < 5; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
    }
    printf("\nNumbers: ");
    for(int i=0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    int largest=arr[0];
    int smallest=arr[0];
    for(int i=0; i < 5; i++)
    {
        if(arr[i] > largest)
        {
            largest=arr[i];
        }
    }
    for(int i=0; i < 5; i++)
    {
        if(arr[i] < smallest)
        {
            smallest=arr[i];
        }
    }
    average=(float)sum/5;
    printf("\n\nLargest: %d\n",largest);
    printf("Smallest: %d\n",smallest);
    printf("Sum: %d\n",sum);
    printf("Average: %.2f",average);
    return 0;
}