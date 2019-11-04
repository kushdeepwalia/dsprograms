//8TH NOVEMEBER
#include<stdio.h>
#include<windows.h>
int Shell_Sort(int arr[], int n)
{
    int gap,j,temp,k;
    for(gap=3; gap>0; gap--)
        for(int i=gap; i<n; i++)
        {
            temp = arr[i];
            for (j=i; j>=gap && arr[j-gap]>temp; j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    return 0;
}
int main()
{
    int i,arr[20],size;
    printf("\n Enter size of the list ");
    scanf("%d",&size);
    printf("\n Enter the list ");
    for(i=0; i<size; i++)
        scanf("%d",&arr[i]);
    Shell_Sort(arr,size);
    printf("\n Sorted list is : ");
    for(i=0; i<size; i++)
        printf("%d ",arr[i]);
    return 0;
}
