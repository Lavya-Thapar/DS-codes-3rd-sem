#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    int data;
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
void push(struct node **head,int element)
{
    struct node *temp=getnode(element);
    if(*head==NULL)
    {
        *head=temp;
        (*head)->next=*head;
        return;
    }
    else
    {
        if((*head)->next==*head)
        {
            (*head)->next=temp;
            temp->next=*head;
            *head=temp;
        }
        else{
            struct node * p=(*head)->next;
            (*head)->next=temp;
            temp->next=p;

        }
    }
}
void pop(struct node **head)
{
    if(*head==NULL)
    {
        printf("underflow");
        return;
    }
    else
    {
        if((*head)->next==*head)
        {
            freenode(*head);
            *head=NULL;
        }
        else{
            struct node *p=(*head)->next;
            (*head)->next=(*head)->next->next;
            freenode(p);
        }
    }
}
void print(struct node **head)
{
    if(*head==NULL)
    {
        printf("empty stack");
    }
    printf("%d ",(*head)->next->data);
    struct node *temp=(*head)->next->next;
    while(temp!=(*head)->next)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    struct node *head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    pop(&head);
    pop(&head);
    print(&head);
}