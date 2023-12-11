#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node {
    int data;
    struct node *nptr;
};

struct node *get_node(int val) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->nptr = NULL;
    temp->data = val;
    return temp;
}

void freenode(struct node *p) {
    free(p);
}

void insert_at_last(struct node **head, struct node **tail, int val) {
    if (*head == NULL) {
        struct node *temp = get_node(val);
        temp->nptr = temp;
        *head = temp;
        *tail = temp;
        return;
    }
    struct node *temp = get_node(val);
    (*tail)->nptr = temp;
    temp->nptr = *head;
    *tail = temp;
    
}

void print(struct node *head) {
    struct node *temp = head;
    printf("%d ", temp->data);
    temp = temp->nptr;
    while (temp != head) {
        printf("%d ", temp->data);
        temp = temp->nptr;
    }
    printf("\n");
}
void mutiply(struct node **head1,struct node **head2)
{
    int length;
    printf("enter the number of digits of number:");
    scanf("%d",&length);
    struct node * ans_head=NULL;
    struct node * ans_tail=head1;
    struct node * p=*head1,*q=*head2;
    int total;
    while(p->data!=-1)
    {
        int carry=0;
        while(q->data!=-1)
        {
            total=(p->data*q->data)+carry;
            int number=total%10;
            carry=total/10;
            insert_at_last(ans_head,ans_tail,total);
            
            q=q->nptr;
        }
        p=p->nptr;
        
    }
    
    
}
int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    long int number=12345;
    insert_at_last(&head, &tail, 5);
    insert_at_last(&head, &tail, 4);
    insert_at_last(&head, &tail, 3);
    insert_at_last(&head, &tail, 2);
    insert_at_last(&head, &tail, 1);
    insert_at_last(&head,&tail,-1);
    struct node *head2 = NULL;
    struct node *tail2 = NULL;
    long int number=12345;
    insert_at_last(&head2, &tail2, 5);
    insert_at_last(&head2, &tail2, 4);
    insert_at_last(&head2, &tail2, 3);
    insert_at_last(&head2, &tail2, 2);
    insert_at_last(&head2, &tail2, 1);
    insert_at_last(&head2,&tail2,-1);
    
}