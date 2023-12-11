#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* getnode(int element)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

struct node* make_tree(int element)
{
    struct node* temp = getnode(element);
    return temp;
}

void set_left(struct node* root, int element)
{
    if (root == NULL)
    {
        printf("Void insertion\n");
        return;
    }
    else if (root->left != NULL)
    {
        printf("Value already present\n");
        return;
    }
    else
    {
        root->left = make_tree(element);
    }
}

void set_right(struct node* root, int element)
{
    if (root == NULL)
    {
        printf("Void insertion\n");
        return;
    }
    else if (root->right != NULL)
    {
        printf("Value already present\n");
        return;
    }
    else
    {
        root->right = make_tree(element);
    }
}

void add_to_tree(struct node** root, int element)
{
    if (*root == NULL)
    {
        *root = make_tree(element);
        return ;
    }
    if ((*root)->data > element)
    {
        add_to_tree(&((*root)->left), element);
    }
    if ((*root)->data < element)
    {
        add_to_tree(&((*root)->right), element);
    }
    
}
void inorder(struct node * root)//left node right
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    
}
void preorder(struct node * root)// node left right
{
    if(root==NULL)
    {
        return ;

    }
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}
void postorder(struct node * root)//left right node
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    
}
int main()
{
    struct node * root=NULL;
    for(int i=0;i<7;i++)
    {
        int element;
        printf("enter element ot add:");
        scanf("%d",&element);
        add_to_tree(&root,element);
    }
    printf("inorder traversal of the tree is:\n");
    inorder(root);
    printf("\n preorder traversal of the tree is:\n");
    preorder(root);
    printf("\n postorder traversal of the tree is:\n");
    postorder(root);

    return 0;
}