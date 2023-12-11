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
    temp->next=NULL;
    return temp;
}
void initialise(struct node **head)
{
    int data;
    printf("intialise the header node with with anything :");
    scanf("%d",&data);
    struct node * temp=getnode(data);
    *head=temp;
    (*head)->next=*head;
}
void freenode(struct node * temp)
{
    free(temp);
}
void insert_at_head(struct node ** head,int element)
{
    //assuming there is a header node already present
    struct node * temp=getnode(element);
    if((*head)->next==*head)//only single node present
    {
        (*head)->next=temp;
        temp->next=*head;
        return;
    }
    else{
        struct node * p=(*head)->next;
        (*head)->next=temp;
        temp->next=p;
        
    }

}
void insert_after(struct node * p,int element)
{
    struct node * temp=getnode(element);
    if(p==NULL)
    {
        printf("void insertion");
        return;
    }
    else
    {
        struct node * q=p->next;
        p->next=temp;
        temp->next=q;
    }
}
void delete_after(struct node *p)
{
    if(p==NULL)
    {
        printf("void deletion");
        return;
    }
    else
    {
        struct node * q=p->next;
        p->next=q->next;
        freenode(q);
    }
}
void print(struct node ** head)
{
    struct node * temp=(*head)->next;
    if(temp==*head)
    {
        printf("empty list");
        return;
    }
    else
    {
        while(temp!=*head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    struct node * head=NULL;
    initialise(&head);
    insert_at_head(&head,10);
    insert_at_head(&head,15);
    insert_after(head->next,20);
    insert_at_head(&head,19);
    print(&head);
    delete_after(head->next);
    print(&head);
}