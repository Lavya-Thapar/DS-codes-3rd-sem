#include <stdio.h>
#include <stdlib.h>
struct node 
{
    struct node * right;
    struct node * left;
    int data;
    int rightthread;
};
struct node * maketree(int val)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=val;
    temp->rightthread=0;
    return temp;
}
struct node * insert(struct node * root)
{
    int val;
    printf("enter the value :");
    scang("%d",&val);
    if(root==NULL)
    {
        root=maketree(val);
        root->righthread=1;
        return root;
    }
    else
    {
        printf("to the left of node %d \n",val);
        root->left=insert(root->left);
        printf("to the right of node %d \n",val);
        root->right=insert(root->right);
        return root;
    }
}
void inorder(struct node * root)
{

}