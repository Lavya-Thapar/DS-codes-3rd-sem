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
void insert_after(struct node **head,struct node * p,int x)
{
    struct node *temp=getnode(x);
    if(p==NULL)
    {
        *head=temp;
        temp->next=NULL;

    }
    if(p->next==NULL)
    {
        p->next=temp;
        temp->next=NULL;
    }
    else{
        struct node * q=p->next;
        p->next=temp;
        temp->next=q;
    }
}
void print(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
}
merge_2_sorted_LL(struct node **head1,struct node **head2,struct node **head3)
{
    struct node *temp1;
    struct node *temp2;
    struct node *temp3=*head3;
    if((*head1)->data<=(*head2)->data)
    {
        temp1=*head1;
        temp2=*head2;
    }
    else
    {
        temp1=*head2;
        temp2=*head1;
    }

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<=temp2->data)
        {
            insert_after(head3,temp3,temp1->data);
            temp1=temp1->next;
            temp3=temp3->next;
        }
        else
        {
            insert_after(head3,temp3,temp2->data);
            temp2=temp2->next;
            temp3=temp3->next;
        }
    }
    while(temp1!=NULL)
    {
        insert_after(head3,temp3,temp1->data);
        temp1=temp1->next;
        temp3=temp3->next;
    }
    while(temp2!=NULL)
    {
        insert_after(head3,temp3,temp2->data);
        temp2=temp2->next;
        temp3=temp3->next;
    }
    print(*head3);

}
int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *head3=NULL;
    insert_after(&head1,head1,10);
    insert_after(&head1,head1,12);
    print(head1);
}