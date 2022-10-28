/*  */
#include <iostream>
using namespace std;
 
void swapAlternate(int arr[],int size){
    for (int i = 0; i < size; i+=2)
    {
        if (i+1<size)              // case-> (i+1<=size)=>then it will swap last and 1st element then exit 
        {
            swap(arr[i],arr[i+1]);
        }
        
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

    int even[4]={1,3,2,4};
    int odd[5]={1,3,2,4,5};
    swapAlternate(even,4);
    printArray(even,4);
    cout<<endl;
    swapAlternate(odd,5);
    printArray(odd,5);

    return 0;
}
 

