#include<stdio.h>
#include<conio.h>
void main()
{
 int i,ar[10],n,k,j,no;
 clrscr();
 printf("\n Enter the size: ");
 scanf("%d",&n);
 printf("\n Enter the elememts: ");
 for( i=0;i<n;i++)
  scanf("%d",&ar[i]);
 printf("\n Enter the number to be inserted: ");
 scanf("%d",&no);
 printf("\n Enter the postion where to be inserted: ");
 scanf("%d",&k);
 j=n;
 while(j>=k-1)
 {
  ar[j+1]=ar[j];
  j=j-1;
 }
 ar[k-1]=no;
 n=n+1;
 printf("\n The new array is: ");
 for(i=0;i<n;i++)
  printf("%d",ar[i]);
 printf("\n\n Kushdeep Singh ");
 getch();
}