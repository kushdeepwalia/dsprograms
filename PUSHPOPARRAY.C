#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
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
void pop()
{
    int item;
    if(top==-1)
    {
        printf("\n Underflow Error");
        return;
    }
    item=stack[top];
    top--;
    printf("\n Popped Element is: %d",item);
}
void display()
{
    int i;
    for(i=0; i<=top; i++)
        printf(" %d",stack[i]);
}
int main()
{
    int ch,item;
    const int max=15;
    do
    {
        system("cls");
        printf("\n 1: PUSH ");
        printf("\n 2: POP ");
        printf("\n 3: DISPLAY ");
        printf("\n 4: QUIT ");
        printf("\n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter number to push ");
            scanf("%d",&item);
            push(max,item);
            printf("\n Updated stack is: ");
            display();
            printf("\n Kushdeep Singh");
            Sleep(2000);
            break;
        case 2:
            pop();
            printf("\n Rest stack is: ");
            display();
            printf("\n Kushdeep Singh");
            Sleep(2000);
            break;
        case 3:
            printf("\n Stack is: ");
            display();
            printf("\n Kushdeep Singh");
            Sleep(2000);
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
