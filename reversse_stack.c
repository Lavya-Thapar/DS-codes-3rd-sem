#include<stdio.h>
#include<string.h>
#include<math.h>
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
void push(struct stack *s,int element)
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
void insert_at_bottom(struct stack *s,int x)
{
    if(is_empty(s))
    {
        push(s,x);
        return;
    }
    else
    {
        int a=pop(s);
        insert_at_bottom(s,x);
        push(s,a);

    }

}
void reverse_stack(struct stack *s)
{
    if(is_empty(s))
    {
        return;
    }
    else{
        int top=pop(s);
        reverse_stack(s);
        insert_at_bottom(s,top);
    }
}

int main()
{
    struct stack s;
    s.top==-1;
    push(&s,1);
    push(&s,2);
    push(&s,3);
    printf("%d ",stack_top(&s));
    reverse_stack(&s);
    printf("%d ",stack_top(&s));

}