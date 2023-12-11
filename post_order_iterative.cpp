#include <iostream>
#include <stack>
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
void post_order_iterative(node * root)
{
    stack<node *> s1;
    stack<node *> s2;
    s1.push(root);
    while(!s1.empty())
    {
        node * x=s1.top();
        s1.pop();
        s2.push(x);
        if(x->left)
        {
            s1.push(x->left);
        }
        if(x->right)
        {
            s1.push(x->right);
        }
    }
    while(!s2.empty())
    {
        node * x=s2.top();
        s2.pop();
        cout<<x->data<<" ";
    }
}
int main()
{
    node * root=NULL;
    root=build_tree(root);
    post_order_iterative(root);
}
