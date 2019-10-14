#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
struct node
{
    int item;
    struct node *next;
}*top=NULL;
void push(int item)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->item=item;
    new_node->next=top;
    top=new_node;
}
int pop()
{
    struct node *node=top;
    int item,c=1;
    if(top==NULL)
    {
        printf("\n Underflow Error");
        c=0;
        return c;
    }
    item=node->item;
    top=top->next;
    printf("\n Deleted Element is: %d",item);
    return c;
}
void display()
{
    int i;
    struct node *node=top;
    while(node!=NULL)
    {
        printf(" %d",node->item);
        node=node->next;
    }
}
int main()
{
    int ch,item,a;
    char c='n';
    const int max=15;
    do
    {
        system("cls");
        printf("\n 1: Inserting elements in list ");
        printf("\n 2: Deleting elements from list ");
        printf("\n 3: Displaying array ");
        printf("\n 4: Quit ");
        printf("\n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            do
            {
                printf("\n Enter number to insert ");
                scanf("%d",&item);
                push(item);
                printf("\n Updated list is: ");
                display();
                printf("\n Press Y to continue pushing ");
                c=getche();
            }
            while(c=='y' || c=='Y');
            printf("\n Kushdeep Singh");
            Sleep(5000);
            break;
        case 2:
            do
            {
                a=pop();
                if(a==1)
                {
                    printf("\n Rest list is: ");
                    display();
                    printf("\n Press Y to continue deleting ");
                    c=getche();
                }
            }
            while((c=='y' || c=='Y') && a==1);
            printf("\n Kushdeep Singh");
            Sleep(5000);
            break;
        case 3:
            printf("\n List is: ");
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
