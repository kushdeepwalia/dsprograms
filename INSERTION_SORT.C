#include<stdio.h>
#include<windows.h>
#include<conio.h>
int insert_sort(int a[],int b[],int n)
{
    int i,low,pos,j,temp;
    low=a[0];
    pos=0;
    for(i=1; i<n; i++)
        if(low>a[i])
        {
            low=a[i];
            pos=i;
        }
    for(i=pos; i>0; i--)
        a[i]=a[i-1];
    b[i]=a[i]=low;
    for(i=1; i<n; i++)
    {
        b[i]=a[i];
        for(j=0; j<i; j++)
            if(b[i]<b[j])
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
    }
    return 0;
}
int main()
{
    int i,a[30],size,b[30];
    printf("\n Enter the size of list: ");
    scanf("%d",&size);
    printf("\n Enter the list: ");
    for(i=0; i<size; i++)
        scanf("%d",&a[i]);
    insert_sort(a,b,size);
    printf("\n\n Sorted list is: \n ");
    for(i=0; i<size; i++)
        printf("%d ",b[i]);
    printf("\n Kushdeep Singh \n");
    return 0;
}
