#include <iostream>
#include <stack>
#include<queue>
using namespace std;
int main()
{
    int arr[10]={-2,-8,3,4,-5,6,-7,9,10,-11};
    // queue<int> q;
    // for(int i=0;i<10;i++)
    // {
    //     q.push(arr[i]);
    // }
    int k;
    cout<<"enter value of K;";
    cin>>k;
    queue<int> q;
    int start=0;
    int end=start+k-1;
    while(!(end==10))
    {
        int flag=1;
        
        int dummy_start=start;
        int dummy_end=end;
        for(int i=dummy_start;i<=dummy_end;i++)
        {
            
            if(arr[i]<0)
            {
                q.push(arr[i]);
                start=start+1;
                end=start+k-1;
                flag=0;
                break;
            }
            
        }
        if(flag==1)
        {
            q.push(0);
            start=start+1;
            end=start+k-1;
        }
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}