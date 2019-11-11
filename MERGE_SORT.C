//THORE GHANTON BAAD DEKHTE HAI ISKO
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
void merging_list(int a[],int b[],int c[],int m,int n)
{
    int i=0,j=0,k=0;
    while(i<m && j<n)
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    while(i<m)
        c[k++]=a[i++];
    while(j<n)
        c[k++]=b[j++];
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
    int list1[20],list2[20],list3[40],size_list1,size_list2,i,j=0,k=0;
    printf("\n Enter the size of list 1 : ");
    scanf("%d",&size_list1);
    printf("\n Enter list 1 : ");
    for(i=0; i<size_list1; i++)
        scanf("%d",&list1[i]);
    printf("\n Enter the size of list 2 : ");
    scanf("%d",&size_list2);
    printf("\n Enter list 2 : ");
    for(i=0; i<size_list2; i++)
        scanf("%d",&list2[i]);
    i=0;
    while(i<size_list1)
        list3[k++]=list1[i++];
    while(j<size_list2)
        list3[k++]=list2[j++];
    printf("\n Merged Unsorted List is : ");
    for(i=0; i<k; i++)
        printf(" %d ",list3[i]);
    merge_sort(list1,0,size_list1-1);
    merge_sort(list2,0,size_list2-1);
    merging_list(list1,list2,list3,size_list1,size_list2);
    printf("\n\n Sorted List 1 is: ");
    for(i=0; i<size_list1; i++)
        printf(" %d ",list1[i]);
    printf("\n\n Sorted List 2 is: ");
    for(i=0; i<size_list2; i++)
        printf(" %d ",list2[i]);
    printf("\n\n Merged Sorted List is : ");
    for(i=0; i<size_list1+size_list2; i++)
        printf(" %d ",list3[i]);
    printf("\n Kushdeep Singh \n");
    return 0;
}
