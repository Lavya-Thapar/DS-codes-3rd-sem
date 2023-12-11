
#include<iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp=q.front();
        
        if(temp== NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);

            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

node *build_binary_tree(node *&root, int element)
{
    if (root == NULL)
    {
        return new node(element);
    }
    else
    {
        if (element >= root->data)
        {
            root->right = build_binary_tree(root->right, element);
        }
        else
        {
            root->left = build_binary_tree(root->left, element);
        }
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cout << "Enter value (enter -1 to stop): ";
    cin >> data;
    while (data != -1)
    {
        root = build_binary_tree(root, data);
        cout << "Enter value (enter -1 to stop): ";
        cin >> data;
    }
}

int main()
{
    node *root = NULL;
    cout << "Enter data to make binary tree:\n";
    takeInput(root);
    cout << "Level Order Traversal:\n";
    levelOrderTraversal(root);
    return 0;
}
