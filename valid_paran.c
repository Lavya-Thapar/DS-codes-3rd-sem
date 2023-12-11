#include<stdio.h>
#include<string.h>

#define STACKSIZE 100
struct stack
{
    int top;
    char items[STACKSIZE];

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
char pop(struct stack *s1)
{
    if(is_empty(s1))
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        char x=s1->items[s1->top];
        s1->top--;
        return x;
    }
}
char stack_top(struct stack *s)
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
void valid_paranthesis(struct stack *s, char exp[])
{
    for(int i=0;exp[i]!=0;i++)
    {
        if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
        {
            push(s,exp[i]);
        }
        else
        {
            if(exp[i]=='}')
            {
                if(stack_top(s)!='{')
                {
                    printf("invalid");
                    return;
                }
                else
                {
                    pop(s);
                }
            }
            if(exp[i]==']')
            {
                if(stack_top(s)!='[')
                {
                    printf("invalid");
                    return;
                }
                else
                {
                    pop(s);
                }
            }
            if(exp[i]==')')
            {
                if(stack_top(s)!='(')
                {
                    printf("invalid");
                    return;
                }
                else
                {
                    pop(s);
                }
            }
            
        }
    }
    if(is_empty(s))
    {
        printf("valid \n");
        return ;
    }
    else
    {
        
        printf("invalid \n");
        return;
    }
}
int main()
{
    char exp[20];
    printf("enter your expression:");
    scanf("%s",exp);
    struct stack s1;
    s1.top=-1;
    valid_paranthesis(&s1,exp);

}