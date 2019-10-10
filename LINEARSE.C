#include<stdio.h>
#include<conio.h>
void main()
{
 int k,loc=0,ar[10],item,n;
 clrscr();
 printf("\n Enter the size: ");
 scanf("%d",&n);
 printf("\n Enter the array: ");
 for(k=0;k<n;k++)
  scanf("%d",&ar[k]);
 printf("\n Enter the number to be searched: ");
 scanf("%d",&item);
 k=1;
 while(loc==0 && k<=n)
 {
  if(item==ar[k])
   loc=k;
  k=k+1;
 }
 if(loc==0)
  printf("\n Number not found");
 else
  printf("\n Number found at %dth postion",loc+1);
 printf("\n\n Kushdeep Singh");
 getch();
}
