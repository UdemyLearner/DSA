#include <iostream>
using namespace std;

/*
memory -> Stack = small size    => Static  memory Allocation  >> int a;
       -> heap  = larger size   => Dynamic memroy Allocation  >> char *ch =  new char;    << "new char" return address of char var crated in heap memory
*/

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}

int main(int argc, char const *argv[])
{
    // char ch = 'g';
    // cout << sizeof(ch) << endl;
    // char *c = &ch;
    // cout << sizeof(c) << endl;
    int n ;
    cin>>n;
    int *arr = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int ans = getSum(arr,n);
    cout<<ans<<endl;
    return 0;
}
