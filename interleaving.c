#include <stdio.h>
#include<stdlib.h>
#define STACKSIZE 100
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
struct stack
{
    int top;
    char items[STACKSIZE];

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
int empty_queue(struct queue *q)
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
    if(empty_queue(q))
    {
        printf("cannot print empty queue");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int is_empty_stack(struct stack *s)
{
    if(s->top==-1)
    {
        
        return 1;
    }
    else
    {
        
        return 0;
    }
}
void push(struct stack *s,int element)
{
    if(s->top==STACKSIZE)
    {
        printf("stack overflow...cannot add more elements");
        return;
    }
    else
    {
        (s->top)++;
        s->items[s->top]=element;
    }
}
int pop(struct stack *s1)
{
    if(is_empty_stack(s1))
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        int x=s1->items[s1->top];
        s1->top--;
        return x;
    }
}
int stack_top(struct stack *s)
{
    if(is_empty_stack(s))
    {
        printf("no element present");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}
void reverse_stack(struct stack *s)
{
    if(is_empty_stack(s))
    {
        return;
    }
    int x=pop(s);
    reverse_stack(s);
    push(s,x);
}
void interleave(struct stack *s,struct queue *q)
{
    struct node *t=q->front;
    int count=0;
    while(t!=NULL)
    {
        count=count+1;
        
        t=t->next;
        
    }
    
    for(int i=0;i<count/2;i++)
    {
        int x=remove_from_queue(q);
        push(s,x);
        printf("%d ",stack_top(s));
    }
    reverse_stack(s);
    while(!is_empty_stack(s))
    {
        int x=pop(s);
        insert(q,x);
    }
    for(int i=0;i<count/2;i++)
    {
        int x=remove_from_queue(q);
        insert(q,x);
    }
    print(q);
}
int main()
{
    struct stack s;
    s.top==-1;
    struct queue q;
    q.front=NULL;
    q.rear=NULL;
    insert(&q,1);
    insert(&q,2);
    insert(&q,3);
    insert(&q,4);
    insert(&q,5);
    insert(&q,6);
    //print(&q);
    interleave(&s,&q);
}