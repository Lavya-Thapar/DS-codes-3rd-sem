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