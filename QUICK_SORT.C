//8TH NOVEMEBER
#include<windows.h>
#include<stdio.h>
void quicksort(int arr[25],int lower,int upper)
{
    int i,j,pivot,temp;
    if(lower<upper)
    {
        pivot=lower;
        i=lower;
        j=upper;
        while(i<j)
        {
            while(arr[i]<=arr[pivot]&&i<upper)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,lower,j-1);
        quicksort(arr,j+1,upper);
    }
}
int main()
{
    int i,count,arr[25];
    printf("\n Enter the size of unsorted list : ");
    scanf("%d",&count);
    printf("\n Enter %d elements: ", count);
    for(i=0; i<count; i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,count-1);
    printf("\n Sorted List is :");
    for(i=0; i<count; i++)
        printf(" %d",arr[i]);
    return 0;
}
