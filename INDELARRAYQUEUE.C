#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
int queue[15],rear=-1,front=-1;
const int max=15;
void insert(int item)
{
    if(rear==max-1)
    {
        printf("\n Overflow Error");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
        rear++;
    queue[rear]=item;
}
int deletion()
{
    int item,c=1;
    if(front==-1)
    {
        printf("\n Underflow Error ");
        c=0;
        return c;
    }
    item=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front++;
    printf("\n Deleted Element is: %d ",item);
    return c;
}
void display()
{
    int i;
    for(i=front; i<=rear; i++)
        if(queue[i]!=0)
            printf("%d ",queue[i]);
        else
            printf("Empty ");

}
int main()
{
    int ch,item,a;
    char c='n';
    do
    {
        system("cls");
        printf("\n 1: Inserting elements in array ");
        printf("\n 2: Deleting elements from array ");
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
                printf("\n press y to continue insert ");
                c=getche();
            }
            while(c=='y');
            printf("\n Kushdeep Singh \n ");
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
                    printf("\n press y to continue deleting ");
                    c=getche();
                }
            }
            while(c=='y' && a==1);
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 3:
            printf("\n Queue is: ");
            display();
            printf("\n Kushdeep Singh \n ");
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
