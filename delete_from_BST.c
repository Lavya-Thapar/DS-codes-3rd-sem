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
struct node * delete_from_bst(struct node * root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(val<root->data)
    {
        root->left=delete_from_bst(root->left,val);
        return root;
    }
    else if(val>root->data)
    {
        root->right=delete_from_bst(root->right,val);
        return root;
    }
    else
    {
        //case 1: no child of root
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
        }
        //case 2: left child present but no right child
        if(root->left!=NULL && root->right==NULL )
        {
            root->data=root->left->data;
            free(root->left);
            root->left=NULL;
        }
        if(root->right!=NULL && root->left==NULL)
        {
            root->data=root->right->data;
            free(root->right);
            root->right=NULL;
        }
        //case 3: left and right both children present
        else
        {
            struct node * succ=root->right;
            struct node * succparent=root;
            while(succ->left!=NULL)
            {
                succparent=succ;
                succ=succ->left;
            
            }
            if(succparent!=root)
            {
                root->data=succparent->left->data;
                free(succ);
                succparent->left=NULL;
            }
            if(succparent==root)
            {
                root->data=root->right->data;
                free(root->right);
                root->right=NULL;
            }
            return root;
        }

    }
}
int main()
{
    struct node * root=NULL;
    add_to_tree(&root,10);
    add_to_tree(&root,5);
    add_to_tree(&root,15);
    add_to_tree(&root,9);
    add_to_tree(&root,17);
    add_to_tree(&root,3);
    inorder(root);
    printf("\n");
    root=delete_from_bst(root,3);
    inorder(root);

}