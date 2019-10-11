#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
struct node
{
    int item;
    struct node *next;
}*top=NULL;
void push(int max,int item)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->item=item;
    new_node->next=top;
    top=new_node;
}
void pop()
{
    int item;
    struct node *node=top;
    if(top==NULL)
    {
        printf("\n Underflow Error");
        return;
    }
    item=node->item;
    top=top->next;
    printf("\n Popped Element is: %d",item);
}
void display()
{
    int i;
    struct node *node=top;
    while(node->next!=NULL)
    {
        printf(" %d",node->item);
        node=node->next;
    }
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
            Sleep(2000);
            break;
        case 2:
            pop();
            printf("\n Rest stack is: ");
            display();
            Sleep(2000);
            break;
        case 3:
            printf("\n Stack is: ");
            display();
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
