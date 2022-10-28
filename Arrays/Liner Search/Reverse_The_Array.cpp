#include <iostream>
using namespace std;

void reverse(int arr[],int n){
    int start=0;
    int end = n-1;
    while (start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    
}

void printArray(int arr[],int n){
    for (size_t i = 0; i < n; i++)
    {
     cout<<arr[i]<<" ";        
    }
}

int main(int argc, char const *argv[])
{
    int arr[3]={1,-2,-1};
    int brr[4]={1,-1,2,-2};
    reverse(arr,3);
    reverse(brr,4);
    printArray(arr,3);
    
    return 0;
}
