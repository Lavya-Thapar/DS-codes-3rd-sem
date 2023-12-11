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
void BreadthFirstSearch(node *root)
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
int main()
{
    node *root=NULL;
    root=build_tree(root);
    cout<<"Breadth First Search Traversal is "<<endl;
    BreadthFirstSearch(root);



}