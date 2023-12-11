#include <iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;


    heap() {
        size = 0;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void insert_into_heap(int element) {
        size++;
        int index = size;
        arr[index] = element;
        while (index > 1) {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index]) {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else {
                return;
            }
        }
    }

    void delete_from_heap() {
        if (size == 0) {
            cout << "Empty heap" << endl;
            return;
        } else {
            // Put the last node in the first position
            arr[1] = arr[size];
            // Delete the last node
            size--;
            int i = 1;

            while (i * 2 <= size) {
                int leftChild = i * 2;
                int rightChild = i * 2 + 1;
                int maxIndex = i;

                if (arr[leftChild] > arr[i]) {
                    maxIndex = leftChild;
                }
                if (rightChild <= size && arr[rightChild] > arr[maxIndex]) {
                    maxIndex = rightChild;
                }

                if (maxIndex != i) {
                    swap(arr[i], arr[maxIndex]);
                    i = maxIndex;
                } else {
                    return;
                }
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
};
void heapify(int *arr,int n,int i)
{
    int largestIndex=i;
    int leftchild=2*i;
    int rightchild=2*i + 1;
    if(leftchild<n && arr[leftchild]>arr[largestIndex])
    {
        largestIndex=leftchild;
    }
    if(rightchild<n && arr[rightchild]>arr[largestIndex])
    {
        largestIndex=rightchild;
    }
    if(largestIndex!=i)//means largestIndex is updated
    {
        swap(arr[i],arr[largestIndex]);
        heapify(arr,n,largestIndex);
    }
    
}
void heap_sort(int *arr,int size)
{
    int temp=size;
    while(temp>1)
    {
        //step 1: swap root and last
        swap(arr[temp],arr[1]);
        //step 2: temp decrement
        temp--;
        //step 3: root ko heapify
        heapify(arr,temp,1);
    }

}
int main() {
    heap h1;
    h1.insert_into_heap(60);
    h1.insert_into_heap(40);
    h1.insert_into_heap(55);
    h1.insert_into_heap(30);
    h1.insert_into_heap(20);
    h1.insert_into_heap(70);
    int choice;
    cout<<"enter 1 for inserting . Enter 2 for deleting and enter 3 to exit";
    cin>>choice;
    while(choice!=3)
    {
        switch(choice)
        {
            case 1:cout<<"entering into heap"<<endl;
            int element;
            cout<<"enter element to insert";
            cin>>element;
            h1.insert_into_heap(element);
            h1.print();
            break;
            case 2: cout<<"Deleting from heap"<<endl;
            h1.delete_from_heap();
            h1.print();
            break;
            
        }
        cout<<"enter 1 for inserting . Enter 2 for deleting and enter 3 to exit";
        cin>>choice;
    }
    // h1.print();
    // h1.delete_from_heap();
    // h1.print();
    int arr[7]={-1,10,20,13,4,5,6};
    for(int i=3;i>=1;i--)
    {
        heapify(&arr[0],7,i);
    }
    for(int i=1;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heap_sort(h1.arr,h1.size);
    h1.print();
    return 0; // Add return 0; at the end of main

}
