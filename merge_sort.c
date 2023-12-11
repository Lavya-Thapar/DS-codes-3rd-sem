#include <stdio.h>
void merge_sort(int A[],int low,int mid,int high)
{
    int i=low,j=mid+1;int B[high+1];int k=0;
    while(i<mid+1 && j<high+1)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            i++;
        }
        else
        {
            B[k]=A[j];
            j++;
        }
        k++;
    }
    if(i==mid+1)
    {
        while(j<high+1)
        {
            B[k]=A[j];
            k++;
        }
    }
    if(j==high+1)
    {
        while(i<mid+1)
        {
            B[k]=A[i];
            k++;
        }
    }
    for(int c=0;c<high+1;c++)
    {
        A[c]=B[c];
    }
}
void break_up(int arr[],int low,int high,int ans[])
{
    int mid=(low+high)/2;
   if(low<high)
   {
        break_up(arr,low,mid,ans);
        break_up(arr,mid+1,high,ans);
        merge_sort(arr,low,mid,high);
   }
}
int main()
{
   
    int arr[7]={22,4,8,11,7,6,21};
    int merge[7];
    break_up(arr,0,7,merge);
}