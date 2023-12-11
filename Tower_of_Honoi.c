#include <stdio.h>
void TOH(char A,char C,char B,int n)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c \n",A,C);
        return;
    }
    TOH(A,B,C,n-1);
    printf("Move the disk %d from %c to %c \n",n,A ,C);
    TOH(B,C,A,n-1);

}
int main()
{
    int n;
    printf("number of towers:");
    scanf("%d",&n);
    char A='A',B='B',C='C';
    TOH(A,C,B,n);
}
