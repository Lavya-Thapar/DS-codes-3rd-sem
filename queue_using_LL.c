#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    int data;
};

struct queue
{
    struct node * front;
    struct node * rear;
    
};
struct node * getnode(int element)
{
    struct node *temp=(struct node *)(malloc)(1*sizeof(struct node));
    temp->data=element;
    return temp;
}
void freenode(struct node * temp)
{
    free(temp);
}
void insert(struct queue *q,int element)
{
    if(q->front==NULL)
    {
        struct node *temp=getnode(element);
        
        q->front=temp;
        q->rear=temp;
    }
    else
    {
        struct node * temp=getnode(element);
        q->rear->next=temp;
        temp->next=NULL;
        q->rear=temp;
        
    }
}
int remove_from_queue(struct queue *q)
{
    int x;
    if(q->front==NULL && q->rear==NULL)
    {
        printf("underflow");
        return 0;
    }
    else
    {
        struct node *temp=q->front;
        q->front=q->front->next;
        x=temp->data;
        if(q->front==NULL)
        {
            q->rear=NULL;
        }
        freenode(temp);
        return x;
    }
}
int empty(struct queue *q)
{
    if(q->front==NULL && q->rear==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void print(struct queue *q)
{
    struct node *temp=q->front;
    if(empty(q))
    {
        printf("cannot print empty queue \n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    
    struct queue q;
    q.front=NULL;
    q.rear=NULL;
    insert(&q,10);
    insert(&q,20);
    insert(&q,30);
    insert(&q,40);
    print(&q);
    remove_from_queue(&q);
    remove_from_queue(&q);
    print(&q);
    remove_from_queue(&q);
    remove_from_queue(&q);
    print(&q);
    
    
    return 0;
}
