#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define STACKSIZE 100
struct stack
{
    int top;
    char items[STACKSIZE];
};
int is_empty(struct stack *s)
{
    if (s->top == -1)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}
void push(struct stack *s, int element)
{
    if (s->top == STACKSIZE)
    {
        printf("stack overflow...cannot add more elements");
        return;
    }
    else
    {
        (s->top)++;
        s->items[s->top] = element;
    }
}
int pop(struct stack *s1)
{
    if (is_empty(s1))
    {
        printf("stack underflow");
        exit(1);
    }
    else
    {
        int x = s1->items[s1->top];
        s1->top--;
        
        return x;
    }
}
char stack_top(struct stack *s)
{
    if (is_empty(s))
    {
        printf("no element present");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}
void split_into_two(struct stack s,struct stack *s1,struct stack *s2)
{
    s1->top=-1;
    s2->top=-1;
    int count=0;
    struct stack s3=s;
    s3.top=-1;
    while(!is_empty(&s3))
    {
        count++;
        pop(&s3);
    }
    for(int i=0;i<count/2;i++)
    {
        int x=pop(&s);
        push(s1,x);
    }
    while(!is_empty(s1))
    {
        int x=pop(s1);
        push(s2,x);//half stack
    }
    printf("top of first half: %d \n",s2->top);
    printf("top of second half: %d \n",s.top);
}
int main()
{
    struct stack s;
    s.top=-1;
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    struct stack stack_first;
    struct stack stack_second;
    split_into_two(s,&stack_first,&stack_second);
}