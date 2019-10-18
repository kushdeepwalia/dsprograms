#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
struct node
{
    int item;
    struct node *next;
}*front=NULL,*rear=NULL;
void insert(int item)
{
    struct node *queue,*new_node;
    if(front==NULL)
    {
        queue=(struct node *)malloc(sizeof(struct node));
        queue->item=item;
        queue->next=front;
        front=queue;
        rear=front;
    }
    else
    {
        queue=front;
        while(queue!=rear)
            queue=queue->next;
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node->item=item;
        new_node->next=queue->next;
        queue->next=new_node;
        rear=new_node;
    }
}
int deletion()
{
    struct node *queue;
    int c=1;
    if(front==NULL)
    {
        printf("\n Underflow Error");
        c=0;
        return c;
    }
    else if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        queue=front;
        printf("\n Deleted Element is: %d ",queue->item);
        front=queue->next;
    }
    return c;
}
void display()
{
    struct node *queue;
    queue=front;
    while(queue!=NULL)
    {
        printf(" %d",queue->item);
        queue=queue->next;
    }
}
int main()
{
    int ch,item,a;
    char c='n';
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
                insert(item);
                printf("\n Updated queue is: ");
                display();
                printf("\n Press Y to continue insert ");
                c=getche();
            }
            while(c=='y' || c=='Y');
            printf("\n Kushdeep Singh");
            system("pause");
            break;
        case 2:
            do
            {
                a=deletion();
                if(a==1)
                {
                    printf("\n Rest queue is: ");
                    display();
                    printf("\n Press Y to continue deleting ");
                    c=getche();
                }
            }
            while((c=='y' || c=='Y') && a==1);
            printf("\n Kushdeep Singh");
            system("pause");
            break;
        case 3:
            printf("\n List is: ");
            display();
            printf("\n Kushdeep Singh");
            system("pause");
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
