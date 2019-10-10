#include<stdio.h>
#include<conio.h>
void main()
{
 int ptr,k,ar[10],n,temp;
 clrscr();
 printf("\n Enter the size: ");
 scanf("%d",&n);
 printf("\n Enter the array: ");
 for(k=0;k<n;k++)
  scanf("%d",&ar[k]);
 for(k=0;k<n;k++)
 {
  ptr=0;
  while(ptr<=n-k)
  {
   if(ar[ptr]>ar[ptr+1])
    {
     temp=ar[ptr];
     ar[ptr]=ar[ptr+1];
     ar[ptr+1]=temp;
    }
   else
    ptr=ptr+1;
  }
 }
 printf("\n The sorted array is:");
 for(k=0;k<n;k++)
  printf("%d ",ar[k]);
 printf("\n\n Kushdeep Singh");
 getch();
}