/* ->Thie is also solved using "2-Pointers" */
#include <iostream>
using namespace std;

printArray(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
sortOne(int arr[], int size)
{

    int i = 0, j = size - 1;

  
   // Sorting out 0 and 1,2
  while(i<=j){
      
      while(arr[i]==0 && i<=j){
          i++;
      }
      while(arr[j]==1 || arr[j] == 2 && i<=j){
          j--;
      }
      
      if(i<=j){
          swap(arr[i], arr[j]);
          i++;
          j--;
      }
  }  
   
   // Sorting out 1 and 2
   j = size-1;
   while(i<j){
      
      while(arr[i]==1 && i<=j){
          i++;
      }
      while(arr[j]==2 && i<=j){
          j--;
      }
      
      if(i<=j){
          swap(arr[i], arr[j]);
          i++;
          j--;
      }       
  }
}


int main(int argc, char const *argv[])
{
    int arr[10] = {1, 2, 1, 0, 1, 0, 0, 2, 0, 2};
    // int arr[10] = {1,0,1,0,1,0,0,1,0,1};
    printArray(arr, 10);
    cout << endl;
    sortOne(arr, 10);
    cout << endl;
    printArray(arr, 10);
    return 0;
}
