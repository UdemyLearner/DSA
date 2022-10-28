#include <iostream>
using namespace std;
int getPivot(int arr[],int n ){
    int s =0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while (s<e)
    {
        if (arr[mid] >= arr[0]){
            s  = mid + 1;
        }
        else {
            e = mid;                                         
        }                                                   
        mid = s + (e-s)/2;
    }
    return s;

}

int targentSearch(int arr[],int start , int end ,int p, int t){
    int s = start , e = end ;
    int k = t ; 
    int mid = s + (e-s)/2;
    while (start <= end)
    {

        if (arr[p] == t)
        {
            return p;
        }

        if (t > arr[p])
        {
            start = p + 1;
        }
        else
        {
            end = p - 1;
        }

        mid = start + (end - start) / 2;
    }
    return t;
    
}

int main(int argc, char const *argv[])
{
    int arr[5] = {11,22,33,1,2};
    int k = 2;
    int p = getPivot(arr,5);
    cout<<getPivot(arr,5);
    cout<< targentSearch(arr , 0, 4, p , 2);
    return targentSearch(arr , 0, 4, p , 2);
}
