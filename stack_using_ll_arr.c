#include <stdio.h>
#include<stdlib.h>
#define SIZE 6

struct nodetype
{
    int info;
    int next;
} stack[SIZE];
int avail=0;
void set_stack()
{
    for(int i=0;i<SIZE-1;i++)
    {
        stack[i].next=i+1;
    }
    stack[SIZE-1].next=-1;
    avail=0;
}
int get_node()
{
    if(avail==-1)
    {
        printf("overflow");
        return 0;
    }
    else{
        int p=avail;
        avail=stack[avail].next;
        return p;
    }
}
void freenode(int p)
{
    
    stack[p].next=avail;
    avail=p;
    return;
}
void push(int val)
{
    int x=get_node();
    stack[x].info=val;
    //stack[x].next=avail-1;
}
int isEmpty()
{
    if(avail==0)
        return 1;
    else
        return 0;
}
void pop()
{
    int x=stack[avail-1].info;
    freenode(avail-1);

}
void print()
{
    int temp=avail-1;
    while(temp>=0)
    {
        printf("%d ",stack[temp].info);
        temp--;
    }
    printf("\n");
}
// void stack_top()
// {
//     printf("%d \n",stack[avail-1]);
// }
int main()
{
    set_stack();
    push(3);
    push(4);
    push(5);
    push(6);
    push(8);
    //push(10);
    
    
    print();
}