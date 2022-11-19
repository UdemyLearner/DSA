#include <iostream>
using namespace std;

void print(int *arr, int size)
{
    cout << "size of array: " << size << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
bool search(int *arr, int size, int k)
{
    print(arr, size);
    // base case
    if (size == 0)
        return false;
    if (arr[0] == k)
        return true;
    else
    {
        bool remaingpart = search(arr + 1, size - 1, k);
        return remaingpart;
    }
}

int main(int argc, const char **argv)
{
    int arr[5] = {0, 1, 2, 3, 4};
    int size = 5;
    int key = 1;
    int ans = search(arr, size, key);
    if (ans)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}