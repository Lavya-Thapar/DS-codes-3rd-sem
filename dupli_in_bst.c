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

int add_to_tree(struct node** root, int element)
{
    if (*root == NULL)
    {
        *root = make_tree(element);
        return 0;
    }
    if ((*root)->data > element)
    {
        return add_to_tree(&((*root)->left), element);
    }
    if ((*root)->data < element)
    {
        return add_to_tree(&((*root)->right), element);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct node* root = NULL;
    char choice;
    choice = 'y';
    while (choice == 'y')
    {
        int element;
        printf("Enter element to add: ");
        scanf("%d", &element);
        int result = add_to_tree(&root, element);
        
        if (result == 1)
        {
            printf("Value already present\n");
        }
        printf("Do you want to add more elements? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character.
    }
    return 0;
}
