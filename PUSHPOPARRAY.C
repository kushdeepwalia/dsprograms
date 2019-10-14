#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
int stack[15],top=-1;
void push(int max,int item)
{
    if(top==max)
    {
        printf("\n Overflow Error");
        return;
    }
    top++;
    stack[top]=item;
}
int pop()
{
    int item,c=1;
    if(top==-1)
    {
        printf("\n Underflow Error");
        c=0;
        return c;
    }
    item=stack[top];
    top--;
    printf("\n Popped Element is: %d",item);
    return c;
}
void display()
{
    int i;
    for(i=0; i<=top; i++)
        printf(" %d",stack[i]);
}
int main()
{
    int ch,item,a;
    char c='n';
    const int max=15;
    do
    {
        system("cls");
        printf("\n 1: Pushing elements in array ");
        printf("\n 2: Popping elements from array ");
        printf("\n 3: Displaying array ");
        printf("\n 4: Quit ");
        printf("\n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            do
            {
                printf("\n Enter number to push ");
                scanf("%d",&item);
                push(max,item);
                printf("\n Updated stack is: ");
                display();
                printf("\n press y to continue pushing ");
                c=getche();
            }
            while(c=='y');
            printf("\n Kushdeep Singh");
            Sleep(5000);
            break;
        case 2:
            do
            {
                a=pop();
                if(a==1)
                {
                    printf("\n Rest stack is: ");
                    display();
                    printf("\n press y to continue popping ");
                    c=getche();
                }
            }
            while(c=='y' && a==1);
            printf("\n Kushdeep Singh");
            Sleep(5000);
            break;
        case 3:
            printf("\n Stack is: ");
            display();
            printf("\n Kushdeep Singh");
            Sleep(5000);
            break;
        case 4:
            exit(0);
        default:
            printf("\n Wrong Choice");
        }
    }
    while(ch!=4);
    return 0;
}
