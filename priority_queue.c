#include <stdio.h>
#define SIZE 10
struct asc_priority_queue//removes the smallest element front the front
{
    int front;
    int rear;
    int items[SIZE];
}pq;
void initialise()
{
    pq.front=0;
    pq.rear=-1;
}
void insertion(int val)
{
    int i=(pq.rear);
    while(pq.items[i]>=val && i!=(pq.front)-1)
    {
        
        i--;
    }
    
    if(pq.items[i]<val && pq.front>0 && i!=-1)
    {
        int check=((i-pq.front)<(pq.rear-i)?1:0);
        if(check==1)
        {
            int temp=pq.front;
            while(temp!=i+1)
            {
                pq.items[temp-1]=pq.items[temp];
                temp++;
            }
            pq.items[temp-1]=val;
            pq.front--;
        }
        else{
            int temp=i+1;
            while(temp!=pq.rear+1)
            {
                pq.items[temp+1]=pq.items[temp];
                temp++;
            }
            pq.rear++;
            pq.items[i+1]=val;
        }

    }
    else if(pq.items[i]<val && pq.front==0 || i==-1)
    {
        int temp=pq.rear;
        while(temp!=i)
        {
            pq.items[temp+1]=pq.items[temp];
            temp--;
        }
        pq.rear++;
        pq.items[i+1]=val;
    }
    else{
        pq.items[i+1]=val;
        pq.rear++;
    }

}
void pq_insert(int val)
{
    if(pq.rear==SIZE-1)
    {
        printf("queue overflow \n");
        return;
    }
    if(pq.rear==-1)
    {
    
        pq.rear++;
        pq.items[pq.rear]=val;
    }
    else
    {
        insertion(val);
    }

}
int pq_min_delete()
{
    int x=pq.items[pq.front];
    pq.front++;
    return x;
}
void print()
{
    for(int i=pq.front;i<pq.rear+1;i++)
    {
        printf("%d ",pq.items[i]);
    }
    printf("\n");
}
int main()
{
    initialise();
    pq_insert(5);
    pq_insert(10);
    pq_insert(15);
    pq_insert(12);
    pq_insert(7);
    pq_insert(8);
    printf("%d \n",pq_min_delete());
    pq_insert(9);
    pq_insert(5);
    pq_insert(18);
    pq_insert(33);
    pq_insert(22);
    pq_insert(11);
    print();

}