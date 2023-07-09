#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    unordered_map<string,int> m;
    pair<string,int> p1 = make_pair("name",1);
    m.insert(p1);
    pair<string,int> p2("hello",2);
    m.insert(p2);
    m["world"] = 1;
    m["world"] = 2;

    //search
    cout<<m["yo"]<<endl;//it it creat an entry if key is not present 
    cout<<m.at("yo")<<endl; // if we use this an map doesnt have entry then it throw an error

    cout<<m.size()<<endl;

    //check for key present or not 0->key absent & 1-> key is present
    cout<<m.count("apple")<<endl;

    //delete an entry from map
    m.erase("yo");

    //iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<"-"<<it->second<<endl;
        it++;
    }





    cout<<endl<<"-----------------------------------"<<endl;
    return 0;
}









