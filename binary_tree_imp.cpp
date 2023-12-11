#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *build_tree(node *root)
{
    int value;
    cout << "enter data for node";
    cin >> value;
    root = new node(value);
    if (value == -1)
    {
        return NULL;
    }

    cout << "For left of node with data :" << root->data << endl;
    root->left = build_tree(root->left);
    cout << "For right of node with data :" << root->data << endl;
    root->right = build_tree(root->right);
    return root;
}
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
void inorder(node * root)//left node right
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(node * root)// node left right
{
    if(root==NULL)
    {
        return ;

    }
    else
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node * root)//left right node
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void buildfromLevelordertrav(node * &root)
{
    int value;
    cout<<"enter value :";
    cin>>value;
    root=new node(value);
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        int leftvalue;
        int rightvalue;
        node * temp=q.front();
        q.pop();
        cout<<"enter value for left of node with value :"<<temp->data;
        cin>>leftvalue;
        if(leftvalue!=-1)
        {
            temp->left=new node(leftvalue);
            q.push(temp->left);
        }
        cout<<"enter value for right of node with value :"<<temp->data;
        cin>>rightvalue;
        if(rightvalue!=-1)
        {
            temp->right=new node(rightvalue);
            q.push(temp->right);
        }

    }
}
int main()
{
    node *root = NULL;
    buildfromLevelordertrav(root);
    
    levelOrderTraversal(root);
    // //1 2 4 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
}
