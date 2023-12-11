#include <stdio.h>
#define SIZE 13
struct stack
{
    int top1;
    int top2;
    int items[SIZE];
};
void push1(struct stack *s,int element)
{
    if(s->top1==s->top2)
    {
        printf("stack overflow");
    }
    else{
        s->items[s->top1]=element;
        s->top1++;
        
    }
}
void push2(struct stack *s,int element)
{
    if(s->top2==s->top1)
    {
        printf("stack overflow");
    }
    else
    {
        s->items[s->top2]=element;
        s->top2--;
    }
}
void pop1(struct stack *s)
{
    if(s->top1==-1)
    {
        printf("stack underflow");
        return;
    }
    else{
        printf("element popped: %d \n",s->items[(s->top1)-1]);
        s->top1--;
    }
}
void pop2(struct stack *s)
{
    if(s->top2==SIZE)
    {
        printf("stack underflow");
        return;
    }
    else{
        printf("element popped: %d \n",s->items[(s->top2)+1]);
        s->top2++;
    }
}
int main()
{
    struct stack stack;
    stack.top1=0;stack.top2=SIZE-1;
    push1(&stack,10);
    push1(&stack,20);
    push1(&stack,30);
    push1(&stack,40);
    push2(&stack,1);
    push2(&stack,2);
    push2(&stack,3);
    push2(&stack,4);
    pop1(&stack);
    pop2(&stack);
    pop1(&stack);
    pop2(&stack);
}