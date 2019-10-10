#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
#include<dos.h>
struct node
{
    int clg_id;
    char clg_name[20];
    struct node *next;
}*start;
void create_list(int clgid,char a[])
{
    struct node *new_node,*node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->clg_id=clgid;
    strcpy(new_node->clg_name,a);
    if(start==NULL)
    {
        new_node->next=new_node;
        start=new_node;
    }
    else
    {
        node=start;
        while(node->next!=start)
            node=node->next;
        new_node->next=start;
        node->next=new_node;
    }
}
void display()
{
    struct node *node;
    if(start==NULL)
    {
        printf("\n List is empty ");
        return;
    }
    node=start;
    printf("\n List is: ");
    do
    {
        printf("\n College id : %d",node->clg_id);
        printf("\n College name : %s",node->clg_name);
        node=node->next;
    }
    while(node!=start);
}
void addtobeg(int clgid,char a[])
{
    struct node *new_node,*node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->clg_id=clgid;
    strcpy(new_node->clg_name,a);
    node=start;
    while(node->next!=start)
        node=node->next;
    node->next=new_node;
    new_node->next=start;
    start=new_node;
}
void addtoend(int clgid,char a[])
{
    struct node *node=start,*new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->clg_id=clgid;
    strcpy(new_node->clg_name,a);
    while(node->next!=start)
        node=node->next;
    node->next=new_node;
    new_node->next=start;
}
void addtopos(int clgid,char a[],int pos)
{
    struct node *new_node,*node=start;
    int c;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->clg_id=clgid;
    strcpy(new_node->clg_name,a);
    for(c=1; c<pos-1; c++)
    {
        if(node->next!=start)
        {
            node=node->next;
        }
    }
    node->next=new_node;
    new_node->next=node->next;
}
void count()
{
    struct node *node=start;
    int cnt=0;
    do
    {
        node=node->next;
        cnt++;
    }
    while(node!=start);
    printf("\n No. of elements are %d ",cnt);
    printf("\n Kushdeep Singh");
}
void delfrombeg()
{
    struct node *node=start;
    if(node==NULL)
    {
        printf("\n Underflow error ");
        return;
    }
    else
    {
        while(node->next!=start)
            node=node->next;
        node->next=start->next;
        start=node->next;
    }
    return;
}
void delfromend()
{
    struct node *node=start;
    if(node==NULL)
    {
        printf("\n Underflow error ");
        return;
    }
    while(node->next->next!=start)
        node=node->next;
    node->next=start;
}
void delfrompos(int node_no)
{
    struct node *node=start;
    int c=1;
    if(node==NULL)
    {
        printf("\n Underflow error ");
    }
    while(c<node_no-1)
    {
        node=node->next;
        c++;
    }
    node->next=node->next->next;
}
int main()
{
    int ch1,ch2,ch,n,clgid,i,pos;
    char a[20];
    start=NULL;
    do
    {
        system("cls");
        printf("\n 1: Create text ");
        printf("\n 2: Insertion ");
        printf("\n 3: Display ");
        printf("\n 4: Count ");
        printf("\n 5: Deletion ");
        printf("\n 6: Quit ");
        printf("\n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter total records ");
            scanf("%d",&n);
            for(i=0; i<n; i++)
            {
                printf("\n Enter College id ");
                scanf("%d",&clgid);
                printf("\n Enter College name ");
                scanf("%s",&a);
                create_list(clgid,a);
            }
            printf("\n Kushdeep Singh ");
            Sleep(4000);
            break;
        case 2:
            do
            {
                printf("\n 1: Insertion at beginning ");
                printf("\n 2: Insertion at end ");
                printf("\n 3: Insertion at specified location ");
                printf("\n 4: Return ");
                printf("\n Enter choice ");
                scanf("%d",&ch1);
                switch(ch1)
                {
                case 1:
                    printf("\n Enter College id ");
                    scanf("%d",&clgid);
                    printf("\n Enter College name ");
                    scanf("%s",&a);
                    addtobeg(clgid,a);
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(4000);
                    break;
                case 2:
                    printf("\n Enter College id ");
                    scanf("%d",&clgid);
                    printf("\n Enter College name ");
                    scanf("%s",&a);
                    addtoend(clgid,a);
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(4000);
                    break;
                case 3:
                    printf("\n Enter College id ");
                    scanf("%d",&clgid);
                    printf("\n Enter College name ");
                    scanf("%s",&a);
                    printf("\n Enter position ");
                    scanf("%d",&pos);
                    addtobeg(clgid,a);
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(4000);
                    break;
                case 4:
                    break;
                default:
                    printf("\n Wrong Choice ");
                }
            }
            while(ch1!=4);
            Sleep(4000);
            break;
        case 3:
            display();
            printf("\n Kushdeep Singh ");
            Sleep(4000);
            break;
        case 4:
            count();
            Sleep(4000);
            break;
        case 5:
            do
            {
                printf("\n 1: Deletion from beginning ");
                printf("\n 2: Deletion from end ");
                printf("\n 3: Deletion specified location ");
                printf("\n 4: Return ");
                printf("\n Enter choice ");
                scanf("%d",&ch2);
                switch(ch2)
                {
                case 1:
                    delfrombeg();
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000);
                    break;
                case 2:
                    delfromend();
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000);
                    break;
                case 3:
                    printf("\n Enter the record number to delete ");
                    scanf("%d",&pos);
                    delfrompos(pos);
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000);
                    break;
                case 4:
                    break;

                default:
                    printf("\n Wrong Choice ");
                }
            }
            while(ch2!=4);
            Sleep(4000);
            break;
        case 6:
            return 0;
        default:
            printf("\n Wrong Choice ");
        }
    }
    while(ch!=6);
    return 0;
}
