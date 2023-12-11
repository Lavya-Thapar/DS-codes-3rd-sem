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

    int delete_from_heap() {
        if (size == 0) {
            cout << "Empty heap" << endl;
            return -1;
        } else {
            // Put the last node in the first position
            int ans=arr[1];
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
                    break;
                }
            }
            return ans;
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
class queue
{
    public:
    heap h1;
    void enqueue(int element)
    {
        h1.insert_into_heap(element);
    }
    int dequeue()
    {
        return h1.delete_from_heap();
    }
    void isempty()
    {
        if(h1.size==0)
        {
            cout<<"empty"<<endl;
        }
        else
        {
            cout<<"non empty"<<endl;
        }
    }
    void print_queue()
    {
        h1.print();
    }

};
int main()
{
    queue q1;
    q1.enqueue(25);
    q1.enqueue(30);
    q1.enqueue(29);
    q1.enqueue(45);
    
    // cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
}