#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLENGTH 30
void substr(char str1[],int start,int end,char str2[])
{
    char str3[30];
    int check=0;
    for(int i=start;i<end+1;i++)
    {
        str3[check]=str1[i];
        check++;
    }
    str3[check]='\0';
    strcpy(str2,str3);
}
int find(char str[])
{
    int length=strlen(str);
    int m,n;
    char temp[MAXLENGTH];
    if(length==0)
    {
        return 0;
    }
    if(isalpha(str[0]))
    {
        return(1);
    }
    if(length<2)
    {
        return 0;
    }
    substr(str,1,length-1,temp);
    m=find(temp);
    if(m==0 || strlen(str)==m/*means no other operand*/)
    {
        return 0;
    }
    substr(str,m+1,length-m-1,temp);
    n=find(temp);
    if(n==0)
    {
        return 0;
    }
    return m+n+1;

}
void convert(char prefix[],char postfix[])
{
    char opernad1[MAXLENGTH],operand2[MAXLENGTH];
    char post1[MAXLENGTH],post2[MAXLENGTH];
    char temp[MAXLENGTH];char op[2];
    int m,n;
    int length=strlen(prefix);
    if(strlen(prefix)==1)
    {
        if(isalpha(prefix[0]))
        {
            postfix[0]=prefix[0];
            postfix[1]='\0';
            return ;
        }
        else
        {
            printf("invalid expression");
            return;
        }
    }
    else
    {
        op[0]=prefix[0];
        op[1]='\0';
        substr(prefix,1,length-1,temp);
        m=find(temp);//finds the first operand
        substr(prefix,m+1,length-m-1,temp);
        n=find(temp);
        substr(prefix,1,m,opernad1);
        substr(prefix,m+1,n,operand2);
        convert(opernad1,post1);
        convert(operand2,operand2);
        strcat(post1,post2);
        strcat(post1,op);
        substr(post1,0,length,postfix);
        
    }
    printf("%s",postfix);

}
int main()
{
    char prefix[30];
    printf("enter prefix expression:");
    scanf("%s",prefix);
    char postfix[30];
    convert(prefix,postfix);
}