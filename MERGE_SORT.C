#include<stdio.h>
#include<windows.h>
void merge(int arr[],int lower, int mid, int upper)
{
    int i,j,k,n1=(mid-lower+1),n2=upper-mid,L[n1],R[n2];
    for(i=0; i<n1; i++)
        L[i]=arr[lower+i];
    for(j=0; j<n2; j++)
        R[j]=arr[mid+1+j];
    i=0,j=0,k=lower;
    while(i<n1 && j<n2)
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}
int merge_sort(int arr[],int lower,int upper)
{
    if(lower<upper)
    {
        int mid=lower+((upper-lower)/2);
        merge_sort(arr,lower,mid);
        merge_sort(arr,mid+1,upper);
        merge(arr,lower,mid,upper);
    }
    return 0;
}
int main()
{
    int list[20],size,i;
    printf("\n MERGE SORT ");
    printf("\n Enter the size of list : ");
    scanf("%d",&size);
    printf("\n Enter list : ");
    for(i=0; i<size; i++)
        scanf("%d",&list[i]);
    merge_sort(list,0,size-1);
    printf("\n Sorted List is: ");
    for(i=0; i<size; i++)
        printf("%d ",list[i]);
    printf("\n Kushdeep Singh \n");
    return 0;
}
