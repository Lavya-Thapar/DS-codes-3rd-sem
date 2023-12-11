#include <stdio.h>
#include <string.h>
#include <math.h>
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
void push(struct stack *s, char element)
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
char pop(struct stack *s1)
{
    if (is_empty(s1))
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        char x = s1->items[s1->top];
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
void remove_adj_duplicates(struct stack *s,char string[])
{
    char ans[20];
    for(int i=0;string[i]!=0;i++)
    {
        if(is_empty(s) || stack_top(s)!=string[i])
        {
            push(s,string[i]);
        }
        else
        {
            if(stack_top(s)==string[i])
            {
                pop(s);
            }
        }
    }
    int i=0;
    while(!is_empty(s))
    {
        ans[i]=stack_top(s);
        pop(s);
        i++;
    }
    ans[i]='\0';
    for(int i=0;i<(strlen(ans))/2;i++)
    {
        char temp=ans[i];
        ans[i]=ans[strlen(ans)-i-1];
        ans[strlen(ans)-i-1]=temp;
    }
    printf("%s",ans);

}
int main()
{
    struct stack s;
    s.top=-1;
    char string[20];
    printf("enter the expression:");
    scanf("%s",string);
    remove_adj_duplicates(&s,string);

}