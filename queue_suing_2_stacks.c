#include <stdio.h>
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
void enque(struct stack *s,int val)
{
    push(s,val);
}
void deque(struct stack *s1,struct stack *s2)
{
    if(is_empty(s2))
    {
        if(is_empty(s1))
        {
            printf("cannot remove elements...queue underflow");
            return;
        }
        while(!is_empty(s1))
        {
            push(s2,stack_top(s1));
            int x=pop(s1);
        }
        
    }
    int x2=pop(s2);
    printf("element popped %d \n",x2);
}
int is_empty_queue(struct stack *s1,struct stack *s2)
{
    return((is_empty(s1) && is_empty(s2))?1:0);
}
int main()
{
    struct stack s1,s2;
    s1.top=-1;s2.top=-1;
    enque(&s1,5);
    enque(&s1,10);
    enque(&s1,15);
    deque(&s1,&s2);

}