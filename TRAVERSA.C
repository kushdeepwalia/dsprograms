#include<stdio.h>
#include<conio.h>
void main()
{
 int i,k,ar[10],n;
 clrscr();
 printf("\n Enter the size: ");
 scanf("%d",&n);
 printf("\n Enter the elements: ");
 for(i=0;i<n;i++)
  scanf("%d",&ar[i]);
 k=0;
 printf("\n The array is: ");
 while(k<n)
 {
  printf("%d ",ar[k]);
  k++;
 }
 printf("\n\n Kushdeep Singh ");
 getch();
}