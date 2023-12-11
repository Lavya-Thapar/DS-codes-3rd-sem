#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *getnode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = val;
    return temp;
}

void freenode(struct node *p)
{
    free(p);
}

void initialise(struct node **head)
{
    int val;
    printf("Enter the value of the header node: ");
    scanf("%d", &val);

    *head = getnode(val);
    (*head)->next = *head;
    (*head)->prev = *head;
}

void insert_at_head(struct node **head, int element)
{
    if ((*head)->next == *head) // Only a single node
    {
        struct node *temp = getnode(element);
        (*head)->next = temp;
        temp->prev = *head;
        temp->next = *head;
        (*head)->prev = temp;
    }
    else
    {
        struct node *temp = getnode(element);
        struct node *p = (*head)->next;
        (*head)->next = temp;
        temp->prev = *head;
        temp->next = p;
        p->prev = temp;
    }
}

void insert_after(struct node *p, int element)
{
    struct node *temp = getnode(element);
    struct node *q = p->next;
    p->next = temp;
    temp->prev = p;
    temp->next = q;
    q->prev = temp;
}

void insert_before(struct node *p, int element)
{
    insert_after(p->prev, element);
}

void delete(struct node *p)
{
    if (p == NULL)
    {
        printf("Void deletion");
        return;
    }
    struct node *q = p->prev;
    struct node *temp = p->next;
    p->next = NULL;
    p->prev = NULL;
    q->next = temp;
    temp->prev = q;
    freenode(p);
}

void print(struct node **head)
{
    struct node *temp = (*head)->next;
    if (temp == *head)
    {
        printf("Empty list\n");
        return;
    }
    else
    {
        while (temp != *head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct node *head = NULL;
    initialise(&head);
    insert_at_head(&head, 10);
    insert_at_head(&head, 20);
    insert_at_head(&head, 30);
    insert_after(head->next, 40);
    print(&head);
    insert_before(head,99);
    delete(head->next);
    print(&head);
    return 0;
}
