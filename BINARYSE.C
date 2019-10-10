#include<stdio.h>
#include<conio.h>
void main()
{
 int k,loc=0,beg,end,mid,ar[10],item,n;
 clrscr();
 printf("\n Enter the size: ");
 scanf("%d",&n);
 printf("\n Enter the array: ");
 for(k=0;k<n;k++)
  scanf("%d",&ar[k]);
 printf("\n Enter the number to be searched: ");
 scanf("%d",&item);
 beg=0;
 end=n-1;
 mid=(beg+end)/2;
 while(beg<=end && ar[mid]!=item)
 {
  if(item<ar[mid])
   end=mid-1;
  else
   beg=mid+1;
  mid=(beg+end)/2;
 }
 if(ar[mid]==item)
  loc=mid;
 else
  loc=NULL;
 if(loc==NULL)
  printf("\n Number not found");
 else
  printf("\n Number found at %dth postion",loc+1);
 printf("\n\n Kushdeep Singh");
 getch();
}