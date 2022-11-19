#include <iostream>
using namespace std;

int getSum(int *arr, int size)
{
    //base case
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    //recusive call
    int call = getSum(arr + 1, size - 1);
    int sum = arr[0] + call;
    return sum;
}

int main(int argc, const char **argv)
{
    int arr[5] = {2, 4, 6, 8, 9};
    int size = 5;
    int sum = getSum(arr, size);
    cout << sum << endl;
    return 0;
}