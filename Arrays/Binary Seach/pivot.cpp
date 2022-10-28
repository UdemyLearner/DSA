/*  =>  This is used to Sreach an element in an rotated array  */

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
            e = mid;                                         // * e = mid insted of e = mid - 1 *
        }                                                   // => will make s, e, mid all same & then return either of them 

        mid = s + (e-s)/2;

    }
    return s;

}

int main(int argc, char const *argv[])
{
    int arr[6] = {11,22,33,1,2,3};
    cout<<getPivot(arr,6);
    return 0;
}
