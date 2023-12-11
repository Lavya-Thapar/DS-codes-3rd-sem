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
int prec(char c1, char c2)
{
    if (c1 == '$')
    {
        return 1;
    }
    else if (c1 == '*' && (c2 != '$'))
    {
        return 1;
    }
    else if (c1 == '+' && (c2 == '+' || c2 == '-'))
    {
        return 1;
    }
    else if (c1 == '-' && (c2 == '-' || c2 == '+'))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
void in_to_post(struct stack *s, char exp[], char post_exp[])
{
    int j = 0;
    for (int i = 0; exp[i] != 0; i++)
    {
        char symbol = exp[i];

        if (symbol >= 'a' && symbol <= 'z')
        {
            post_exp[j] = symbol;
            j++;
        }
        else
        {
            if (symbol != ')' && symbol != '(' && !is_empty(s) && stack_top(s) != '(')
            {
                while (!is_empty(s) && prec(stack_top(s), symbol))
                {
                    char top = pop(s);
                    post_exp[j] = top;
                    j++;
                }
            }
            else if (!is_empty(s) && stack_top(s) == '(')
            {
                push(s, symbol);
            }
            else if (symbol == '(')
            {
                push(s, symbol);
            }
            else if (symbol == ')')
            {
                while (!is_empty(s) && stack_top(s) != '(')
                {
                    char top = pop(s);
                    post_exp[j] = top;
                    j++;
                }
                char last = pop(s);
            }
            if (is_empty(s) && symbol != '(' && symbol != ')')
            {
                push(s, symbol);
            }
        }
    }
    while (!is_empty(s))
    {
        char x = pop(s);
        // if (x != '(')
        // {
            post_exp[j] = x;
            j++;
        //}
    }
    post_exp[j] = '\0';
    printf("%s", post_exp);
}
int main()
{
    struct stack s;
    s.top = -1;
    char exp[30];
    printf("enter the infix expression:");
    scanf("%s", exp);
    char post_exp[30];
    in_to_post(&s, exp, post_exp);
}