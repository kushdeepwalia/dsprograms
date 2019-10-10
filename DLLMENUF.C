//to create a double link list with nodes having info about employees and perform insertion at beginning and deletion from end.
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
#include<dos.h>
struct node
{
    int emp_id;
    char emp_name[20];
    struct node *next;
    struct node *prev;
}*start;
void create_list(int empid,char a[])
{
    struct node *node,*new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->emp_id=empid;
    strcpy(new_node->emp_name,a);
    new_node->next=NULL;
    new_node->prev=NULL;
    if(start==NULL)
        start=new_node;
    else
    {
        node=start;
        while(node->next!=NULL)
            node=node->next;
        node->next=new_node;
        new_node->prev = node;
    }
}
void displayfor()
{
    struct node *node;
    if(start==NULL)
    {
        printf("\n List is empty ");
        return;
    }
    node=start;
    printf("\n List is: ");
    printf("\n Employee id      Employee name");
    while(node!=NULL)
    {
        printf("\n      %d\t     %s",node->emp_id,node->emp_name);
        node=node->next;
    }
}
void displayback()
{
    struct node *node;
    if(start==NULL)
    {
        printf("\n List is empty ");
        return;
    }
    node=start;
    printf("\n List is: ");
    while(node->next!=NULL)
        node=node->next;
    printf("\n Employee id      Employee name");
    while(node!=NULL)
    {
        printf("\n      %d\t     %s",node->emp_id,node->emp_name);
        node=node->prev;
    }
}
void addtobeg(int empid,char a[])
{
    struct node *new_node;
    struct node *node=start;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->emp_id=empid;
    strcpy(new_node->emp_name,a);
    new_node->next=start;
    node->prev=new_node;
    start=new_node;
}
void delfromend()
{
    struct node *node=start;
    if(node==NULL)
    {
        printf("\n Underflow error ");
    }
    while(node->next->next!=NULL)
        node=node->next;
    node->next=NULL;
}
int main()
{
    int ch1,ch2,ch3,ch,n,empid,ptr,i,pos;
    char a[20];
    start=NULL;
    do
    {
        system("cls");
        printf("\n 1: Create text ");
        printf("\n 2: Insertion ");
        printf("\n 3: Display ");
        printf("\n 4: Deletion ");
        printf("\n 5: Quit ");
        printf("\n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter no. of records ");
            scanf("%d",&n);
            for(i=0; i<n; i++)
            {
                printf("\n Enter Employee Id ");
                scanf("%d",&empid);
                printf("\n Enter Employee name ");
                scanf("%s",&a);
                create_list(empid,a);
            }
            printf("\n Kushdeep Singh ");
            Sleep(2000);
            break;
        case 2:
            printf("\n Enter the record to be insert ");
            printf("\n Enter Employee Id ");
            scanf("%d",&empid);
            printf("\n Enter Employee name ");
            scanf("%s",&a);
            addtobeg(empid,a);
            displayfor();
            printf("\n Kushdeep Singh ");
            Sleep(4000);
            break;
        case 3:
            do
            {
                printf("\n 1: Display from forward ");
                printf("\n 2: Display from backward ");
                printf("\n 3: Return ");
                printf("\n Enter choice ");
                scanf("%d",&ch2);
                switch(ch2)
                {

                case 1:
                    displayfor();
                    printf("\n Kushdeep Singh ");
                    Sleep(4000);
                    break;
                case 2:
                    displayback();
                    printf("\n Kushdeep Singh ");
                    Sleep(4000);
                    break;
                case 3:
                    break;
                default:
                    printf("\n Wrong Choice ");
                }
                system("cls");
            }
            while(ch2!=3);
            break;
        case 4:
            delfromend();
            displayfor();
            printf("\n Kushdeep Singh ");
            Sleep(4000);
            break;
        case 5:
            return 0;
        default:
            printf("\n Wrong Choice ");
        }
    }
    while(ch!=5);
    return 0;
}
