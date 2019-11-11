#include<stdio.h>
#include<windows.h>
#include<math.h>
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
int Shell_Sort(int arr[], int n)
{
    int gap,*sublist1,*sublist2,*garbage,size,i,j,k,temp,a,b;
    if(n%2==0)
        gap=n/2;
    else
        gap=(n+1)/2;
    while(gap>0)
    {
        for(a=0; a<gap; a++)
        {
            size=ceil((float)n/gap);
            sublist1=new int[size];
            sublist2=new int[size];
            for(i=0,j=0; i<n && j<size; i+=gap,j++)
                sublist1[j]=arr[i+a];
            insert_sort(sublist1,sublist2,size);
            for(i=0,j=0; i<n && j<size; i+=gap,j++)
                arr[i+a]=sublist2[j];
        }
        gap--;
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
    printf("\n\n Sorted list is: \n ");
    for(i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n Kushdeep Singh \n");
    return 0;
}
