#include<stdio.h>
#include<conio.h>
void main()
{
 int i,ar[10],n,k,j;
 clrscr();
 printf("\n Enter the size: ");
 scanf("%d",&n);
 printf("\n Enter the elememts: ");
 for(i=0;i<n;i++)
  scanf("%d",&ar[i]);
 printf("\n Enter the postion: ");
 scanf("%d",&k);
 for(j=k-1;j<n-1;j++)
   ar[j]=ar[j+1];
 n=n-1;
 printf("\n The new array is: ");
 for(i=0;i<n;i++)
  printf("%d ",ar[i]);
 printf("\n\n Kushdeep Singh ");
 getch();
}