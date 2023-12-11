#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
};
struct node * getnode(int element)
{
    struct node *temp=(struct node *)(malloc)(1*sizeof(struct node));
    temp->data=element;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
struct node * make_tree(int element)
{
    struct node * temp=getnode(element);
    return temp;
}
void set_left(struct node *root,int element)
{
    if(root==NULL)
    {
        printf("void insertion");
        return;
    }
    else if ((root)->left!=NULL)
    {
        printf("value already present");
        return;
    }
    else
    {
        (root)->left=make_tree(element);
    }
}
void set_right(struct node *root,int element)
{
    if(root==NULL)
    {
        printf("void insertion");
        return;
    }
    else if ((root)->right!=NULL)
    {
        printf("value already present");
        return;
    }
    else
    {
        (root)->right=make_tree(element);
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
    root=make_tree(1);
    set_left(root,2);
    set_right(root,3);
    set_left(root->left,4);
    set_right(root->left,5);
    set_left(root->right,6);
    set_right(root->right,7);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
}