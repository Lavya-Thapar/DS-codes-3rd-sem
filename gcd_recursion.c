#include <stdio.h>
int min_of(int x,int y)
{
    return ((x>y?y:x));
}
int gcd(int big, int small)
{
;
    if(small==0)
    {
        return big;
    }
    else
    {
        gcd(small,big%small);
    }
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    // printf("GCD is: ");
    int small = min_of(x, y);
    int big = x + y - small;
    // if (big % small == 0)
    // {
    //     printf("%d", small);
    //     return 0;
    // }
    // else
    // {
    //     for (int i = small; i > 0; i--)
    //     {
    //         if (big % i == 0 && small % i == 0)
    //         {
    //             printf("%d", i);
    //             return 0;
    //         }
    //     }
    // }
    
    int ans=gcd(big,small);
    printf("%d",ans);

}