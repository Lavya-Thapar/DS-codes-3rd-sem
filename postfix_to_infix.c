#include <stdio.h>
#include<string.h>
#include<math.h>
#define STACKSIZE 100
struct stack
{
    int top;
    char * items[STACKSIZE];

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
void push(struct stack *s,char *p)
{
    if(s->top==STACKSIZE)
    {
        printf("stack overflow...cannot add more elements");
        return;
    }
    else
    {
        (s->top)++;
        s->items[s->top]=p;
    }
}
char * pop(struct stack *s1)
{
    if(is_empty(s1))
    {
        printf("stack underflow");
        return NULL;
    }
    else
    {
        char *p=s1->items[s1->top];
        s1->top--;
        return p;
    }
}
char * stack_top(struct stack *s)
{
    if(is_empty(s))
    {
        printf("no element present");
        return NULL;
    }
    else
    {
        return s->items[s->top];
    }
}
int isoperator(char c)
{
    if(c=='+' || c=='-' || c=='/' || c=='*')
    {
        return 1;
    }
    else{
        return 0;
    }
}
void substring(char *p,int index,int length,char *q)
{
    int c=0;
    while(c<length)
    {
        q[c]=p[index+c-1];
        c++;
    }
    q[c]='\0';
}
char * post_to_in(struct stack *s,char postfix[])
{
    
    //char *i=postfix;
    char temp[20];
    for(int i=0;postfix[i]!=0;i++)
    {
        if(!isoperator(postfix[i]))
        {
            substring(postfix,i,1,temp);
            push(s,temp);
            printf("%s ",stack_top(s));
        }
        else
        {
            char *op1=pop(s);
            char *op2=pop(s);
            char z[2];
            substring(postfix,i,1,z);
            strcat(op2,z);
            strcat(op2,op1);
            push(s,op2);
        }
    }
    char *ans=pop(s);
    return ans;
}
int main()
{
    struct stack s;
    s.top=-1;
    char exp[20]="ab+cd-/";
    char *ans=post_to_in(&s,exp);
    printf("%s",*ans);

}