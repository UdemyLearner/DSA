// faster than insertionSort , selection sort , bublle sort
#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    // copying values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    for (size_t i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    //merge 2 sorred arrays 
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    delete []first;
    delete []second;
}

void megeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    // left part
    megeSort(arr, s, mid);
    // right part
    megeSort(arr, mid + 1, e);
    // merge
    merge(arr, s, e);
}

int main(int argc, char const *argv[])
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    megeSort(arr, 0, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
