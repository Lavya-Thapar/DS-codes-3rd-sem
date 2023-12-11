#include <stdio.h>
#define SIZE 5
struct queue{
    int front;
    int rear;
    int items[SIZE];

};
int isEmpty(struct queue *q)
{
    if(q->rear==q->front && q->front==SIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert(struct queue *q,int element)
{
    if((q->front)-(q->rear)==1 || (q->rear==SIZE -1 && q->front==0))
    {
        printf("stack overflow..");
        return;
    }
    else if(q->rear==SIZE-1 )
    {
        q->rear=0;
        q->items[q->rear]=element;
    }
    else
    {
        q->rear++;
        q->items[q->rear]=element;
    }
    printf("element inserted is %d \n",q->items[q->rear]);
}
int remove_ele(struct queue *q)
{
    
    if(isEmpty(q))
    {
        printf("queue underflow..");
        return 0;
    }
    else
    {
        int x;
        if(q->front==SIZE-1)
        {
            x=q->items[0];
            q->front=0;
        }
        else{
            x=q->items[(q->front)+1];
            q->front++;
        }
       
        return x;
    }
}

int main()
{
    struct queue q;
    q.front=SIZE-1;
    q.rear=SIZE-1;
    insert(&q,1);
    insert(&q,2);
    insert(&q,3);
    printf("%d ",remove_ele(&q));
    printf("%d ",remove_ele(&q));
    printf("%d ",remove_ele(&q));
    printf("%d ",remove_ele(&q));
    
}