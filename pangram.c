#include<stdio.h>
#include<string.h>
#include<math.h>
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
void initialise(struct stack *s)
{
    for(char i='z';i>='a';i++)
    {
        push(s,i);
        printf("%c ",stack_top(s));
    }
}
void panagram_string(struct stack *s,char arr[])
{
    int j=0;
    char ans[27];
    while(!is_empty(s))
    {
        char top=pop(s);
        for(int i=0;arr[i]!=0;i++)
        {
            if(top==arr[i])
            {
                ans[j]=top;
                j++;
                break;
            }
        }
    }
    ans[j]='\0';
    printf("%s",ans);
}
int main()
{
    struct stack s;
    s.top=-1;
    initialise(&s);
    char arr[50]="data structure";
    panagram_string(&s,arr);
}