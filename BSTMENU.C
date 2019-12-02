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
            printf("\n\n Case II: Deletion of number which have 1 child ");
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
    if(node->info==num)
        return;
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
int get_inorder_successor(struct node *node)
{
    while (node && node->left != NULL)
        node = node->left;
    return node->info;
}
struct node *delete_a_node(int item, struct node *node)
{
    struct node *temp;
    int inorder_successor;
    if(node == NULL)
        return node;
    if ( item < node->info )
        node->left =  delete_a_node(item, node->left);
    else if ( item > node->info )
        node->right = delete_a_node(item, node->right);
    else
    {
        if ( node->left == NULL )
        {
            temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            temp = node->left;
            free(node);
            return temp;
        }
        inorder_successor = get_inorder_successor(node->right);
        node->info = inorder_successor;
        node->right = delete_a_node( inorder_successor, node->right );
    }
    return node;
}
int main()
{
    int ch,item,num;
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
            printf("\n Enter the item you want to insert : (press -1 to finish) \n ");
            while(item!=-1)
            {
                printf("\n Enter Item : \t");
                scanf("%d", &item);
                if (item!= -1)
                    root = insert_into_tree(item, root);
            }
            printf("\n Tree created ");
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 2:
            if(root==NULL)
                printf("\n The tree is empty.....no deletion possible ");
            else
            {
                printf("\n Enter the value you want to delete : \t");
                scanf("%d", &num);
                printf("\n Position of %d : Root",num);
                position(root,num);
                delete_a_node(num,root);
            }
            printf("\n Kushdeep Singh \n ");
            system("pause");
            break;
        case 3:
            printf("\n");
            if(root==NULL)
                printf(" Tree is empty");
            else
                display_tree(root,0);
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
