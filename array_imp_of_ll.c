#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct nodetype
{
    int info;
    int next;
} node[SIZE];

void set_node()
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        node[i].next = i + 1;
    }
    node[SIZE - 1].next = -1;
}
int getnode(int * a)
{
    if (*a == -1)
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        int p = *a;
        *a = node[*a].next;
        
        return p;
    }
}
void freenode(int p,int * a)
{
    node[p].next = *a;
    *a = p;
    return;
}
void print()
{
    
    for(int temp=0;temp<3;temp++)
    {
        printf("%d ",node[temp].info);
        
    }
}
int main()
{
    int avail = 0;
    int x;
    set_node();
    x=getnode(&avail);
    
    node[x].info=1;
    int y=getnode(&avail);
    
    node[y].info=5;
    int z=getnode(&avail);
    
    node[z].info=8;
    print();
}
