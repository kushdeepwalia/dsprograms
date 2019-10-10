#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
#include<dos.h>
struct node
{
    int roll_num;
    char name[20];
    struct node *next;
    struct node *prev;
}*start;
void create_list(int rn,char a[])
{
    struct node *node,*new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->roll_num=rn;
    strcpy(new_node->name,a);
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
    while(node!=NULL)
    {
        printf("\n Roll number: %d",node->roll_num);
        printf("\n Name: %s",node->name);
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
    while(node!=NULL)
    {
        printf("\n Roll number: %d",node->roll_num);
        printf("\n Name: %s",node->name);
        node=node->prev;
    }
}
void addtobeg(int rn,char a[])
{
    struct node *new_node;
    struct node *node=start;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->roll_num=rn;
    strcpy(new_node->name,a);
    new_node->next=start;
    new_node->prev=NULL;
    node->prev=new_node;
    start=new_node;
}
void addtoend(int rn,char a[])
{
    struct node *node=start;
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->roll_num=rn;
    strcpy(new_node->name,a);
    while(node->next!=NULL)
        node=node->next;
    node->next=new_node;
    new_node->prev=node;
    new_node->next=NULL;
}
void addtopos(int rn,char a[],int pos)
{
    struct node *node=start;
    int c;
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->roll_num=rn;
    strcpy(new_node->name,a);
    for(c=1; c<pos-1; c++)
    {
        if(node->next!=NULL)
        {
            node=node->next;
        }
    }
    new_node->next=node->next;
    node->next->prev=new_node;
    node->next=new_node;
    new_node->prev=node;
}
void count()
{
    struct node *node=start;
    int cnt=0;
    while(node!=NULL)
    {
        node=node->next;
        cnt++;
    }
    printf("\n No. of elements are %d ",cnt);
}
void delfrombeg()
{
    struct node *node=start;
    if(node==NULL)
    {
        printf("\n Underflow error ");
        return;
    }
    start=node->next;
    start->prev=NULL;
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
    while(node->next->next!=NULL)
        node=node->next;
    node->next=NULL;
}
void delfrompos(int node_no)
{
    struct node *node=start;
    int c=1;
    if(node==NULL)
    {
        printf("\n Underflow error ");
        return;
    }
    while(c<node_no-1)
    {
        node=node->next;
        c++;
    }
    node->next=node->next->next;
    node->next->next->prev=node;
}
int main()
{
    int ch1,ch2,ch3,ch,n,rn,ptr,i,pos;
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
            printf("\n Enter no. of records ");
            scanf("%d",&n);
            for(i=0; i<n; i++)
            {
                printf("\n Enter Roll number ");
                scanf("%d",&rn);
                printf("\n Enter Name ");
                scanf("%s",&a);
                create_list(rn,a);
            }
            printf("\n Kushdeep Singh ");
            Sleep(4000); break;
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
                    printf("\n Enter the record to be insert ");
                    printf("\n Enter Roll number ");
                    scanf("%d",&rn);
                    printf("\n Enter Name ");
                    scanf("%s",&a);
                    addtobeg(rn,a);
                    displayfor();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 2:
                    printf("\n Enter the record to be insert ");
                    printf("\n Enter Roll number ");
                    scanf("%d",&rn);
                    printf("\n Enter Name ");
                    scanf("%s",&a);
                    addtoend(rn,a);
                    displayfor();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 3:
                    printf("\n Enter the record to be insert ");
                    printf("\n Enter Roll number ");
                    scanf("%d",&rn);
                    printf("\n Enter Name ");
                    scanf("%s",&a);
                    printf("\n Enter the position ");
                    scanf("%d",&pos);
                    addtopos(rn,a,pos);
                    displayfor();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 4:
                    break;
                default:
                    printf("\n Wrong Choice ");
                }
            }
            while(ch1!=4);
            Sleep(4000); break;
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
                    Sleep(1000); break;
                case 2:
                    displayback();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 3:
                    break;

                default:
                    printf("\n Wrong Choice ");
                }
            }
            while(ch2!=3);
            Sleep(4000); break;
        case 4:
            count();
            Sleep(4000); break;
        case 5:
            do
            {

                printf("\n 1: Deletion from beginning ");
                printf("\n 2: Deletion from end ");
                printf("\n 3: Deletion specified location ");
                printf("\n 4: Return ");
                printf("\n Enter choice ");
                scanf("%d",&ch3);
                switch(ch3)
                {
                case 1:
                    delfrombeg();
                    displayfor();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 2:
                    delfromend();
                    displayfor();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 3:
                    printf("\n Enter the record number to delete ");
                    scanf("%d",&pos);
                    delfrompos(pos);
                    displayfor();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 4:
                    break;

                default:
                    printf("\n Wrong Choice ");
                }
            }
            while(ch3!=4);
            Sleep(4000); break;
        case 6: return 0;
        default:
            printf("\n Wrong Choice ");
        }
    }
    while(ch!=6);
    return 0;
}
