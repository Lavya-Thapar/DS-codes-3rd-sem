#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nptr;
    
};
struct node * stack;

struct node * get_node(int val)
{
    struct node * temp;
    temp=(struct node *)(malloc)(1*sizeof(struct node));
    temp->nptr=NULL;
    temp->data=val;
    return temp;
    
}
void freenode(struct node * p)
{
    free(p);
}
void insert(int val)
{
    if(stack==NULL)
    {
        struct node * temp=get_node(val);
        stack=temp;
    }
    else{
        struct node * temp=get_node(val);
        temp->nptr=stack;
        stack=temp;
    }
}
void push(int val)
{
   insert(val);
}
void pop()
{
    struct node *temp=stack;
    int x=temp->data;
    if(temp==NULL)
    {
        printf("underflow");
        return;
    }
    else
    {
        
        stack=stack->nptr;
        freenode(temp);
        printf("element popped is :%d \n",x);
    }
}
void stack_top()
{
    printf("top-most element: %d \n",stack->data);
}
int main()
{
    push(5);
    push(10);
    push(15);
    push(20);
    stack_top();
    pop();
    stack_top();
    return 0;
}