#include<stdio.h>
struct nodetype
{
    int info;
    int used;
}node[100];
void initialise_tree()
{
    int val;
    printf("enter value for root node:");
    scanf("%d",&val);
    node[0].info=val;
    node[0].used=1;
    for(int i=1;i<100;i++)
    {
        node[i].used=0;
    }
}
void set_left(int p,int val)
{
    int leftchild=2*p+1;
    if(leftchild<100 && node[leftchild].used==0)
    {
        node[leftchild].info=val;
        node[leftchild].used=1;
    }
    else{
        printf("invalid insertion");
    }
}
void set_right(int p,int val)
{
    int rightchild=2*p+2;
    if(rightchild<100 && node[rightchild].used==0)
    {
        node[rightchild].info=val;
        node[rightchild].used=1;
    }
    else{
        printf("invalid insertion");
    }
}
void print_tree()
{
    for(int i=0;i<100;i++)
    {
        if(node[i].used!=0)
        {
            printf("%d ",node[i].info);
        }
        
    }
    printf("\n");
}
int main()
{
    initialise_tree();
    set_left(0,5);
    set_right(0,10);
    set_left(1,7);
    set_right(1,12);
    set_right(1,13);
    print_tree();

}