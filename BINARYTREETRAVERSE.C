#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<windows.h>
#include<conio.h>
struct node
{
    char info;
    struct node *left;
    struct node *right;
};
struct node *insert_into_tree(char item, struct node *node)
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
    {
        printf("\n Going to left side. ");
        node->left=insert_into_tree(item,node->left);
    }
    else
    {
        printf("\n Going to right side. ");
        node->right=insert_into_tree(item,node->right);
    }
}
int preorder_traversal(struct node *node)
{
    if(node==NULL)
    {
        printf("\n The tree is empty ");
        return 0;
    }
    else
        printf(" %c ",node->info);
    if (node->left!=NULL)
        preorder_traversal(node->left);
    if (node->right!=NULL)
        preorder_traversal(node->right);
    return 0;
}
int inorder_traversal(struct node *node)
{
    if(node==NULL)
    {
        printf("\n The tree is empty ");
        return 0;
    }
    if(node->left!=NULL)
        inorder_traversal(node->left);
    if(node!=NULL)
        printf(" %c ", node->info);
    if(node->right!=NULL)
        inorder_traversal(node->right);
    return 0;
}
int postorder_traversal(struct node *node)
{
    if(node==NULL)
    {
        printf("\n The tree is empty ");
        return 0;
    }
    if (node->left != NULL)
        postorder_traversal(node->left);
    if (node->right != NULL)
        postorder_traversal(node->right);
    if(node!=NULL)
        printf(" %c ", node->info);
    return 0;
}
void traversal(struct node *node)
{
    int ch;
    printf("\n 1: Preorder Traversal ");
    printf("\n 2: Inorder Traversal ");
    printf("\n 3: Postorder Traversal ");
    printf("\n Choose the type of traversal : ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1 :
        printf("\n Preorder Traversal of tree is : ");
        preorder_traversal(node);
        printf("\n Kushdeep Singh \n ");
        system("pause");
        break;
    case 2 :
        printf("\n Inorder Traversal of tree is : ");
        inorder_traversal(node);
        printf("\n Kushdeep Singh \n ");
        system("pause");
        break;
    case 3 :
        printf("\n Postorder Traversal of tree is : ");
        postorder_traversal(node);
        printf("\n Kushdeep Singh \n ");
        system("pause");
        break;
    case 4:
        return;
    }
    system("cls");
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
    printf("%c \n",node->info);
    display_tree(node->left,l);
    return 0;
}
int main()
{
    int ch,a;
    char item;
    struct node *root=NULL;
    do
    {
        system("cls");
        printf("\n 1: Insertion in Tree ");
        printf("\n 2: Traverse Tree ");
        printf("\n 3: Display Tree ");
        printf("\n 4: Exit ");
        printf("\n Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            do
            {
                printf("\n Enter Item : ");
                scanf(" %c",&item);
                root = insert_into_tree(item, root);
                printf("\n Press y to continue: ");
                a=getche();
            }
            while(a=='y' || a=='Y');
            printf("\n Items were entered in root : %c \n",root->info);
            printf("\n Kushdeep Singh \n");
            system("pause");
            break;
        case 2:
            traversal(root);
            break;
        case 3:
            printf("\n");
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
