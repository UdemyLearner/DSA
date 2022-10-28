/*  https://www.spoj.com/problems/EKO/ */

#include <iostream>
using namespace std;

long long minValue(long long arr[], long long size)
{
    long long min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
long long maxValue(long long arr[], long long size)
{
    long long max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

long long bs(long long arr[],long long size, long long min, long long max, long long height)
{
    long long s = min;
    long long e = max;
    long long m = s + (e - s) / 2; // 10+20/2 = 15
    long long c = 0;
    long long temp=0;

    while (s < e)
    {
        temp=0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] > m)
            {
                c = arr[i] - m;
                temp+=c;           
            }
            //cout<<endl<<temp<<endl;
            
        }
        if(temp==height){
            return m;
        }
        if(temp>height){
                s = m + 1 ;
            }
            else{
                e = m ;
            }

            m = s + (e - s) / 2;
    }
    return m;
}

int main()
{
    long long size,height;
    cin >> size>>height;
    long long arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    long long min = minValue(arr, size);
    long long max = maxValue(arr, size);
    long long ans =  bs(arr,size, min, max, height);
    cout << ans;
   // return ans;
   return 0;
}








































// /*  https://www.spoj.com/problems/EKO/ */

// #include <iostream>
// using namespace std;

// int minValue(int arr[], int size)
// {
//     int min = arr[0];
//     for (int i = 1; i < size; i++)
//     {
//         if (arr[i] < min)
//         {
//             min = arr[i];
//         }
//     }
//     return min;
// }
// int maxValue(int arr[], int size)
// {
//     int max = arr[0];
//     for (int i = 1; i < size; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// int bs(int arr[],int size, int min, int max, int height)
// {
//     int s = min;
//     int e = max;
//     int m = s + (e - s) / 2; // 10+20/2 = 15
//     int c = 0;
//     int temp=0;

//     while (s < e)
//     {
//         temp=0;

//         for (int i = 0; i < size; i++)
//         {
//             if (arr[i] > m)
//             {
//                 c = arr[i] - m;
//                 temp+=c;           
//             }
//             //cout<<endl<<temp<<endl;
            
//         }
//         if(temp==height){
//             return m;
//         }
//         if(temp>height){
//                 s = m + 1 ;
//             }
//             else{
//                 e = m ;
//             }

//             m = s + (e - s) / 2;
//     }
//     return m;
// }

// int main(int argc, char const *argv[])
// {
//     int size,height;
//     cin >> size>>height;
//     cout<<size<<"  "<<height;
//     int arr[size];
//     for (int i = 0; i < size; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i];
//     }
    
//     // int arr[5] = {4, 42, 40, 26, 46};
//     // int arr1[4] = {20 ,15 ,10 ,17};
//     // int min = minValue(arr, 5);
//     // int max = maxValue(arr, 5);
//     // cout << bs(arr,5, min, max, 20);
//     return 0;
// }
