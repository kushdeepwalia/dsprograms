#include<windows.h>
#include<stdio.h>
int pivot;
void partition(int arr[],int beg,int end)
{
    int left=beg,temp,right=end,flag=0,k;
    pivot=beg;
    while(flag==0)
    {
        printf("\n Pivot Element is: %d",arr[pivot]);
        while(arr[pivot]<=arr[right] && pivot!=right)
            right--;
        if(pivot==right)
            flag=1;
        else if(arr[pivot]>arr[right])
        {
            temp=arr[pivot];
            arr[pivot]=arr[right];
            arr[right]=temp;
            pivot=right;
        }
        if(flag==0)
        {
            while(arr[pivot]>=arr[left] && pivot!=left)
                left++;
            if(pivot==left)
                flag=1;
            else if(arr[pivot]<arr[left])
            {
                temp=arr[pivot];
                arr[pivot]=arr[left];
                arr[left]=temp;
                pivot=left;
            }
        }
    }
}
int quicksort(int arr[],int beg,int end)
{
    if(beg<end)
    {
        partition(arr,beg,end);
        quicksort(arr,beg,pivot-1);
        quicksort(arr,pivot+1,end);
    }
    return 0;
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
    printf("\n\n Sorted list is: \n ");
    for(i=0; i<count; i++)
        printf(" %d",arr[i]);
    printf("\n Kushdeep Singh \n");
    return 0;
}
