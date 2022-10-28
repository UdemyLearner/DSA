#include <iostream>
using namespace std;

int firstOcc(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
            end = mid-1;            // For Last Occcurence => start = mid + 1;
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int a[5] = {1, 4, 4, 4, 5};
    int index = firstOcc(a, 5, 4);
    cout << index;
    return 0;
}
