#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    //max Heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(5);
    pq.push(2);
    pq.push(3);
    cout<<"top->"<<pq.top()<<endl;
    pq.pop();
    cout<<"Top->"<<pq.top()<<endl;
    cout<<"Size->"<<pq.size()<<endl<<" "<<endl;

    //min heap
    priority_queue< int,vector<int>,greater<int> > minheap;
    minheap.push(4);
    minheap.push(5);
    minheap.push(2);
    minheap.push(3);
    cout<<"top->"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Top->"<<minheap.top()<<endl;
    cout<<"Size->"<<minheap.size()<<endl;

    return 0;
}
