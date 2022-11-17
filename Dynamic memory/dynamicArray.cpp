#include <iostream>
using namespace std;

/*
memory -> Stack = small size    => Static  memory Allocation  >> int a;
       -> heap  = larger size   => Dynamic memroy Allocation  >> char *ch =  new char;    << "new char" return address of char var crated in heap memory
*/

int getSum(int *arr, int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    // char ch = 'g';
    // cout << sizeof(ch) << endl;
    // char *c = &ch;
    // cout << sizeof(c) << endl;
    int n;
    cin >> n;
    int *arr = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);
    cout << ans << endl;

    while (true)
    {
        int i = 5;
    }

    while (true)
    {
        // this is dangerous reasone stated below
        int *ptr = new int;
        int *ptr1 = new int;
        int *ptr11 = new int;
        int *ptr111 = new int;
        int *ptr1111 = new int;
 
    }

/*    
    delete i;
    delete []arr; 

    used to free heap memory , as heap memory is not free automatically
*/            
    return 0;
}
