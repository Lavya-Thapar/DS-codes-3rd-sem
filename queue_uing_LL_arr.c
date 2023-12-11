#include <stdio.h>
#include<stdlib.h>
#define SIZE 100

struct nodetype
{
    int info;
    int next;
} node[SIZE];
struct queue
{
    int front,rear;
}q;
int avail=0;
void set_node()
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        node[i].next = i + 1;
    }
    node[SIZE - 1].next = -1;
}
int getnode()
{
    if (avail == -1)
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        int p =avail;
        avail = node[avail].next;
        
        return p;
    }
}
void freenode(int p)
{
    node[p].next =avail;
    avail= p;
    return;
}
void print()
{
   int i=q.front;
   while(node[i].info>0)
   {
        printf("%d ",node[i].info);
        i=node[i].next;
   }
   printf("\n");
}

void queue_initialise()
{
    q.front=q.rear=-1;
}
void insert(int x)
{
    int p=getnode();
    node[p].info=x;
    if(q.front==-1)
    {
        q.front=p;
    }
    else{
        node[q.rear].next=p;
    }
    q.rear=p;
}
int remove_from_queue()
{
    if(q.front==-1)
    {
        printf("void removal ");
        exit(1);
    }
    else{
        int p=q.front;
        int x=node[q.front].info;
        q.front=node[q.front].next;
        if(q.front==-1)
            q.rear==-1;
        freenode(p);
        return x;
    }
}
int main()
{
    set_node();
    queue_initialise();
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    print();
    remove_from_queue();
    print();
    
}
