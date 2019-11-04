//25TH OCTOBER
#include<stdio.h>
#include<windows.h>
#include<conio.h>
int insert_sort(int a[],int n)
{
    int i,j,t,k;
    printf("\n");
    for(i=0; i<n-1; i++)
        for(j=0; j<n-(i+1); j++)
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    return 0;
}
int main()
{
    int i,arr[20],size=1,num;
    char test='n';
    arr[size-1]=-1000;
    do
    {
        printf("\n Enter the number to list: ");
        scanf("%d",&num);
        arr[size++]=num;
        insert_sort(arr,size);
        printf("\n Press Y to continue inserting number ");
        test=getche();
    }
    while(test=='Y' || test=='y');
    printf("\n Sorted list is: ");
    for(i=1; i<size; i++)
        printf("%d ",arr[i]);
    return 0;
}
