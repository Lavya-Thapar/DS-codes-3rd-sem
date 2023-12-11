#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
struct node * getnode(int val)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}
struct graph_nodes
{
    int data;
    struct node * adjptr;
}graph[5];
void add_to_adj(struct node * temp,struct node * p)
{
    struct node * q=temp->next;
    temp->next=p;
    p->next=q;
}
void add_edge(int i,int j)
{
    add_to_adj(graph[i].adjptr,getnode(j));
    add_to_adj(graph[j].adjptr,getnode(i));
}
void print_adj_list(int i)
{
    struct node * temp=graph[i].adjptr->next;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void print_graph()
{
    for(int i=0;i<5;i++)
    {
        printf("node %d is connected to nodes: ",graph[i].data);
        print_adj_list(i);
    }
    printf("\n");
}
int main()
{
    printf("enter values for nodes \n:");
    for(int i=0;i<5;i++)
    {
        printf("value of node %d :",i);
        scanf("%d",&graph[i].data);
    }
    add_edge(0,2);
    add_edge(1,3);
    add_edge(1,4);
    add_edge(2,1);
    add_edge(0,4);
    print_graph();
}