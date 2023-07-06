#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class heap {
public:
    int arr[100000];
    int size = 0;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "nothing to delete " << endl;
            return;
        }
        // step 1 : swap 1st and last node
        arr[1] = arr[size];
        // step2: deletion of last node
        size--;
        // step3:rearrange the tree
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i] , arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left])
        largest = left;
    if(right <= n && arr[largest] < arr[right])
        largest = right;
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void buildMinHeap(int arr[],int n,int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[smallest] > arr[left])
        smallest = left;
    if(right < n && arr[smallest] > arr[right])
        smallest = right;
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}

void heapSort(int arr[],int n){
    int size = n;
    while(size>1){
        //step1
        swap(arr[size],arr[1]);
        //step2
        size--;
        //step3
        heapify(arr,size,1);
    }
}

int main(int argc, char const *argv[])
{

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromheap();
    h.print();

    int arr[6] = { -1,54,53,55,52,50};
    int n = 5;
    // heapify for 1 base indexing
        for(int i = n/2;i>0;i--){
            heapify(arr,n,i);
        }
        
    // heapify for 0 base indexing
    /*    for(int i = (size/2 - 1);i>=0;i--){
                heapify(ans,size,i);
            }
        void heapify(vector<int> &arr,int n,int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
    
        if(left < n && arr[largest] < arr[left])
            largest = left;
        if(right < n && arr[largest] < arr[right])
            largest = right;
        if(largest != i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    */
    cout<<"printin array now"<<endl;
    for(int i = 1;i<=n;i++){
        cout << arr[i] << " ";
    }

    heapSort(arr,n);
    cout<<"printin array now"<<endl;
    for(int i = 1;i<=n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}
