#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *getnode(int val)
{
    struct node *temp = (struct node *)(malloc(sizeof(struct node)));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->next = NULL;
    temp->data = val;
    return temp;
}

void freenode(struct node *p)
{
    free(p);
}

void pop(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    freenode(temp);
}

void push(struct node **head, int val)
{
    struct node *temp = getnode(val);
    if (*head == NULL)
    {
        *head = temp;
        printf("pushed: %d \n", (*head)->data);
    }
    else
    {
        temp->next = *head;
        *head = temp;
        printf("pushed: %d \n", (*head)->data);
    }
}

void insertafter(struct node *p, int x)
{
    if (p == NULL)
    {
        printf("Invalid node\n");
        return;
    }
    struct node *temp = getnode(x);
    temp->next = p->next;
    p->next = temp;
    printf("inserted: %d \n", p->next->data);
}

void deleteafter(struct node *p)
{
    if (p == NULL || p->next == NULL)
    {
        printf("Invalid node or no node to delete\n");
        return;
    }
    struct node *q = p->next;
    p->next = q->next;
    q->next = NULL;
    freenode(q);
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete(struct node **head, int val)
{
    struct node *p = *head;
    struct node *q = NULL;

    while (p != NULL)
    {
        if (p->data == val && q == NULL)
        {
            *head = p->next; // Update the head
            pop(&p);         // Free the old head
            p = *head;       // Move to the next node
        }
        else
        {
            if (p->data == val)
            {
                p = p->next;
                deleteafter(q);
            }
            else
            {
                p = p->next;
                if (q == NULL)
                {
                    q = *head; // Initialize q to head
                }
                else
                {
                    q = q->next;
                }
            }
        }
    }
}

int main()
{
    struct node *head = NULL;
    push(&head, 5);
    push(&head, 8);
    push(&head, 12);
    insertafter(head, 10);
    insertafter(head->next, 5);
    
    
    print(head);
    delete(&head,5);
    print(head);
    return 0;
}
