#include <stdio.h>
int remove_duplicate(int arr[],int size)
{
    
    int xor_object=0;
    for(int i=0;i<size;i++)
    {
        
        xor_object=(xor_object ^ arr[i]);

    }
    // for(int i=1;i<size;i++)
    // {
    //     xor_object=xor_object^i;
    // }
    
    return xor_object;
}
int main()
{
    int arr[10]={1,3,3,4,5,6,7,2,9,10};
    printf("%d ",remove_duplicate(arr,10));
}