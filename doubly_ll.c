#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node * prev;
    struct node * next;
    int data;
};

struct node * getnode(int val)
{
    struct node *temp= (struct node *)(malloc)(1*sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=val;
    return temp;
}
void insert_at_head(struct node **head,struct node **tail,int element)
{
    struct node *p=getnode(element);
    if(*head==NULL)
    {
        *head=p;
        *tail=p;
        
    }
    else{
        p->next=*head;
        (*head)->prev=p;
        (*head)=p;
    }
}
void freenode(struct node *p)
{
    free(p);
}
void insert_at_last(struct node ** tail,int val)
{
    struct node * temp=getnode(val);
    (*tail)->next=temp;
    temp->prev=*tail;
    *tail=temp;
}
void insert_after(struct node * p,int val)
{
    struct node * temp=getnode(val);
    if(p->next==NULL)
    {
        p->next=temp;
        temp->prev=p;
        return;
    }
    else{
        struct node * q=p->next;
        p->next=temp;
        temp->prev=p;
        q->prev=temp;
        temp->next=q;
    }
}
void delete_after(struct node * p)
{
    struct node * q=p->next;
   
    p->next=q->next;
    q->prev=NULL;
    q->next=NULL;
    q->prev=NULL;
    p->next->prev=p;
    freenode(q);
}
void print(struct node *head)
{
    struct node * temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    struct node * head=NULL;
    struct node * tail=head;
    insert_at_head(&head,&tail,10);
    insert_at_last(&tail,15);
    print(head);
    insert_at_last(&tail,20);
    print(head);
    insert_after(head,25);
    print(head);
    insert_at_head(&head,&tail,16);
    print(head);
}