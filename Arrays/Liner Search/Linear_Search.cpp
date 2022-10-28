#include<iostream>
using namespace std;

bool search(int arr[],int size,int key){
    
    for (int i = 0; i<size ;i++)
    {
        if (arr[i]==key)
        {
            return 1;                                           // 1 -> Means Condition is True
        }    
    }
    return 0;
}

int main(int argc, const char** argv) {

    int arr[10]= {5,-2,5,10,-55,-9,7,-2};
    cout<<"Enter the element for search "<<endl;
    int key;
    cin>>key;
    bool found = search(arr,10,key);
    if (found)      
    {
        cout<<"Key Found";
    }
    else
    {
        cout<<"Key not found";
    }
    return 0;
}

