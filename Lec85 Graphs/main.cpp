#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    public:
        unordered_map<T,list<T>> adj;

    void addEdge(T u,T v,bool direction){
        //direction = 0 -> undirected

        adj[u].push_back(v);
        if(direction==0)
            adj[v].push_back(u);

    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }

};

/*
// To Creat adj list using Vector {better complexity}
vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
*/

int main(int argc, char const *argv[])
{

    int n;
    cout<<"no of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"no edges"<<endl;
    cin>>m;

    graph<int> g;

    for (size_t i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    
    g.print();

    return 0;
}
