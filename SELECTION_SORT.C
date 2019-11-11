#include<stdio.h>
#include<windows.h>
int select_sort(int a[],int n)
{
    int i,j,t,min,pos,k;
    for(i=0; i<n-1; i++)
    {
        min=a[i];
        pos=i;
        for(j=i+1; j<n; j++)
            if(a[j]<min)
            {
                min=a[j];
                pos=j;
            }
        t=a[i];
        a[i]=a[pos];
        a[pos]=t;
        printf("\n  ");
        for(k=0; k<n; k++)
            printf("%d ",a[k]);
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
    select_sort(arr,size);
    printf("\n\n Sorted list is: \n ");
    for(i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n Kushdeep Singh \n");
    return 0;
}
