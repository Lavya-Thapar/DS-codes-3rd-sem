#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node * getnode(int element)
{
    struct Node *temp=(struct Node *)(malloc)(1*sizeof(struct Node));
    temp->data=element;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
struct Node * make_tree(int element)
{
    struct Node * temp=getnode(element);
    return temp;
}
void set_left(struct Node *root,int element)
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
void set_right(struct Node *root,int element)
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
// struct Node* createNode(int key) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode-> = key;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

void findMaxNodesLevel(struct Node* root, int *maxLevel, int *maxNodeCount) {
    if (root == NULL) {
        return;
    }

    struct Node * queue[1000];
    int front = -1, rear = -1;

    rear++;
    queue[rear] = root;

    while (front != rear) 
    {
        int currentlevelnodes=rear-front;
        if(currentlevelnodes>*maxNodeCount)
        {
            *maxNodeCount=currentlevelnodes;
            *maxLevel=*maxLevel+1;
        }
        for(int i=0;i<currentlevelnodes;i++)
        {
            struct Node * temp=queue[front+1];
            front++;
            if(temp->left)
            {
                rear++;
                queue[rear]=temp->left;
            }
            if(temp->right)
            {
                rear++;
                queue[rear]=temp->right;
            }
        }
    }
        
}

// Example usage:
int main() {
    struct Node* root = make_tree(1);
    set_left(root,2);
    set_right(root,3);
    set_left(root->left,4);
    set_right(root->left,5);
    set_left(root->right,6);
    set_right(root->right,7);
    set_right(root->right->right,5);
    set_left(root->right->right,20);
    set_right(root->left->right,5);
    set_left(root->left->right,5);
    set_left(root->right->left,30);
    int maxLevel = 0, maxNodeCount = 0;
    findMaxNodesLevel(root, &maxLevel, &maxNodeCount);

    printf("The level with the maximum number of nodes is %d with %d nodes.\n", maxLevel, maxNodeCount);

    return 0;
}
