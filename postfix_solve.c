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
int postfix( char exp[],int size,struct stack stack)
{
    for(int i=0;i<size;i++)
    {
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='$')
        {
            int operand1=pop(&stack);
            int operand2=pop(&stack);
            int output;
            if(exp[i]=='+')
            {
                output=operand1+operand2;
            }
            else if(exp[i]=='-')
            {
                output=operand2-operand1;
            }
            else if(exp[i]=='*')
            {
                output=operand1*operand2;
            }
            else if(exp[i]=='/')
            {
                output=operand2/operand1;
            }
            else{
                output=pow(operand2,operand1);
            }
            push(&stack,output);
        }
        else{
            int value=exp[i]-'0';
            push(&stack,value);
        }
    }
    return pop(&stack);
}
int main()
{
    char expression[100];
    struct stack s1;
    printf("enter the postifix operation:");
    scanf("%s",expression);
    int ans=postfix(expression,strlen(expression),s1);
    printf("%d",ans);
    return 0;

}