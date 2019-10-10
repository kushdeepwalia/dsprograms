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
}*start;
void create_list(int rn,char a[])
{
    struct node *node,*new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->roll_num=rn;
    strcpy(new_node->name,a);
    new_node->next=NULL;
    if(start==NULL)
        start=new_node;
    else
    {
        node=start;
        while(node->next!=NULL)
            node=node->next;
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
    while(node!=NULL)
    {
        printf("\n Roll number: %d",node->roll_num);
        printf("\n Name: %s",node->name);
        node=node->next;
    }
}
void addtobeg(int rn,char a[])
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->roll_num=rn;
    strcpy(new_node->name,a);
    new_node->next=start;
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
    new_node->next=node->next;
    node->next=new_node;
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
    node->next=new_node;
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
void rev()
{
    struct node *p1,*p2,*p3;
    if(start->next==NULL)
        return;
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
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
        start=node->next;
    return;
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
    int ch1,ch2,ch,n,rn,ptr,i,pos;
    char a[20];
    start=NULL;
    do
    {
        system("cls");
        printf("\n 1: Create text ");
        printf("\n 2: Insertion ");
        printf("\n 3: Display ");
        printf("\n 4: Count ");
        printf("\n 5: Reverse ");
        printf("\n 6: Deletion ");
        printf("\n 7: Quit ");
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
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 2:
                    printf("\n Enter the record to be insert ");
                    printf("\n Enter Roll number ");
                    scanf("%d",&rn);
                    printf("\n Enter Name ");
                    scanf("%s",&a);
                    addtoend(rn,a);
                    display();
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
                    display();
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
            display();
            printf("\n Kushdeep Singh ");
            Sleep(4000); break;
        case 4:
            count();
            Sleep(4000); break;
        case 5:
            rev();
            display();
            printf("\n Kushdeep Singh ");
            Sleep(4000); break;
        case 6:
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
                    Sleep(1000); break;
                case 2:
                    delfromend();
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 3:
                    printf("\n Enter the record number to delete ");
                    scanf("%d",&pos);
                    delfrompos(pos);
                    display();
                    printf("\n Kushdeep Singh ");
                    Sleep(1000); break;
                case 4:
                    break;

                default:
                    printf("\n Wrong Choice ");
                }
            }
            while(ch2!=4);
            Sleep(4000); break;
        case 7: return 0;
        default:
            printf("\n Wrong Choice ");
        }
    }
    while(ch!=7);
    return 0;
}
