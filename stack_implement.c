#include<stdio.h>
#include<string.h>

#define STACKSIZE 100
struct stack
{
    int top;
    int items[STACKSIZE];

};
int is_empty(struct stack *s)
{
    if(s->top==-1)
    {
        
        return 1;
    }
    else
    {
        
        return 0;
    }
}
void push(struct stack *s,char element)
{
    if(s->top==STACKSIZE)
    {
        printf("stack overflow...cannot add more elements");
        return;
    }
    else
    {
        (s->top)++;
        s->items[s->top]=element;
    }
}
int pop(struct stack *s1)
{
    if(is_empty(s1))
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        int x=s1->items[s1->top];
        s1->top--;
        return x;
    }
}
int stack_top(struct stack *s)
{
    if(is_empty(s))
    {
        printf("no element present");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}
int main()
{
    struct stack s;
    s.top=-1;
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);
    printf("stack top is: %d \n",stack_top(&s));
    pop(&s);
    pop(&s);
    printf("stack top is: %d \n",stack_top(&s));
    if(is_empty(&s))
    {
        printf("empty stack");
    }
    else
    {
        printf("not empty");
    }
    return 0;

}