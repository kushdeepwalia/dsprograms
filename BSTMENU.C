#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<windows.h>
#include<conio.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root=NULL;
struct node *insert_into_tree(int item, struct node *node)
{
    if(node==NULL)
    {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        new_node->info=item;
        new_node->left =NULL;
        new_node->right=NULL;
        return new_node;
    }
    else if(node->info>=item)
        node->left=insert_into_tree(item,node->left);
    else
        node->right=insert_into_tree(item,node->right);
}
void position(struct node *node,int num)
{
    if (node->info==num)
    {
        if(node->left==NULL && node->right==NULL)
            printf("\n\n Case I: Deletion of number which have no child ");
        else if(node->left==NULL || node->right==NULL)
            printf("\n\n Case II: Deletion of number which have only one child ");
        else if(node->left!=NULL && node->right!=NULL)
            printf("\n\n Case III: Deletion of number which have 2 child ");
    }
    if (node->info>num)
    {
        printf("->Left");
        position(node->left,num);
    }
    else if (node->info<num)
    {
        printf("->Right");
        position(node->right,num);
    }
}
void position_all(struct node *node,int num)
{
    if(node==root)
        printf("\n Position of %d is : Root",num);
    else if (node->info>num)
    {
        printf("->Left");
        position_all(node->left,num);
    }
    else if (node->info<num)
    {
        printf("->Right");
        position_all(node->right,num);
    }
}
int display_tree(struct node *node,int l)
{
    int i;
    if(node==NULL)
    {
        return 0;
    }
    l+=10;
    display_tree(node->right,l);
    for(i=10; i<l; i++)
        printf(" ");
    printf("%d \n",node->info);
    display_tree(node->left,l);
    return 0;
}
int main()
{
    int ch,i=0,pos=-1,item[20],num,n;
    char m='N';
    do
    {
        system("cls");
        printf("\n 1: Insertion in Tree ");
        printf("\n 2: Deletion in Tree ");
        printf("\n 3: Display Tree ");
        printf("\n 4: Exit ");
        printf("\n Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            if(root!=NULL)
            {
                printf("\n Previous tree is deleted ");
                root=NULL;
            }
            printf("\n Enter total number of items : ");
            scanf("%d",&n);
            printf("\n Enter %d Items : ",n);
            for(i=0; i<n; i++)
                scanf("%d",&item[i]);
            for(i=0; i<n ; i++)
                root = insert_into_tree(item[i], root);
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 2:
            if(root==NULL)
                printf("\n The tree is empty.....no deletion possible ");
            else
            {
                printf("\n Enter item to be deleted ");
                scanf("%d",&num);
                for(i=0; i<n; i++)
                {
                    if(item[i]==num)
                    {
                        pos=i;
                        break;
                    }
                }
                if(pos==-1)
                    printf("\n Number not found");
                else
                {
                    printf("\n Position of %d : Root",num);
                    position(root,num);
                    for(i=pos; i<n; i++)
                        item[i]=item[i+1];
                    n--;
                    root=NULL;
                    for(i=0; i<n; i++)
                        root = insert_into_tree(item[i], root);
                }
            }
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 3:
            printf("\n");
            if(root==NULL)
                printf(" Tree is empty");
            else
            {
                display_tree(root,0);
                printf("\n\n TO SEE ELEMENTS WITH THERE POSITION PRESS Y ELSE PRESS N TO MOVE FORWARD ");
                m=getche();
                if(m=='Y' || m=='y')
                    for(i=0; i<n; i++)
                        position_all(root,item[i]);
                else
                    Sleep(2000);
            }
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 4:
            exit(0);
        }
    }
    while(ch!=4);
    return 0;
}
