#include<stdio.h>
#include<string.h>
#include<math.h>
#define PLUSVALUE -1000
#define MINUSVALUE -2000
#define DIVIDEVALUE -3000
#define MULTIPLYVALUE -4000
#define POWERVALUE -5000
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
int output(int op,int sign,char current)
{
    int a;
    int op2=current-'0';
    if(sign==PLUSVALUE)
    {
        a=op+op2;
    }
    if(sign==MINUSVALUE)
    {
        a=op-op2;
    }
    if(sign==MULTIPLYVALUE)
    {
        a=op*op2;
    }
    if(sign==DIVIDEVALUE)
    {
        a=op/op2;
    }
    if(sign==POWERVALUE)
    {
        a=pow(op,op2);
    }
    return a;
}
int prefix(char exp[],int size,struct stack stack)
{
    for(int i=0;i<size;i++)
    {
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='$')
        {
            int value;
            if(exp[i]=='+')
            {
                value=PLUSVALUE;
            }
            if(exp[i]=='-')
            {
                value=MINUSVALUE;
            }
            if(exp[i]=='*')
            {
                value=MULTIPLYVALUE;
            }
            if(exp[i]=='/')
            {
                value=DIVIDEVALUE;
            }
            if(exp[i]=='$')
            {
                value=POWERVALUE;
            }
            push(&stack,value);
        }
        else
        {
            if(stack_top(&stack)==PLUSVALUE || stack_top(&stack)==MINUSVALUE || stack_top(&stack)==MULTIPLYVALUE || stack_top(&stack)==DIVIDEVALUE || stack_top(&stack)==POWERVALUE )
            {
                push(&stack,(exp[i]-'0'));
            }
            else{
                int op=pop(&stack);
                int sign=pop(&stack);
                int to_push= output(op,sign,exp[i]);
                push(&stack,to_push);
            }
        }
    }
    return pop(&stack);
}
int main()
{
    char expression[100];
    struct stack s1;
    printf("enter the pretifix expression:");
    scanf("%s",expression);
    int ans=prefix(expression,strlen(expression),s1);
    printf("%d",ans);
    return 0;
}