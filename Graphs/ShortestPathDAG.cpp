#include<bits/stdc++.h>
#include<list>
#include<iostream>
#include<unordered_map>
using namespace std;

class graph{
    public:
        unordered_map<int, list<pair<int,int>>> adj;

    void addEge(int u,int v,int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i : adj){
            cout<<i.first<<" ->";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
    }

    void dfs(int node,unordered_map<int,bool> &visited,stack<int> &topo){
        visited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first,visited,topo);
            }
        }

        topo.push(node);

    } 

    void getShortestPath(int src,vector<int> &dis,stack<int> &s){
        dis[src] = 0;

        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(dis[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dis[top]+i.first < dis[i.first]){
                        dis[i.first] = dis[top] + i.second;
                    }
                }

            }
        }

    }

};

int main(int argc, char const *argv[])
{
    graph g;

    g.addEge(0,1,5);
    g.addEge(0,2,3);
    g.addEge(1,2,2);
    g.addEge(1,3,6);
    g.addEge(2,3,7);
    g.addEge(2,4,4);
    g.addEge(2,5,2);
    g.addEge(3,4,-1);
    g.addEge(4,5,-2);

    g.printAdj();

    int n=6;
    // Topological ssort
    unordered_map<int,bool> visited;
    stack<int> s;
    for (size_t i = 0; i < n; i++)
    {
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }
    
    int src = 1;
    vector<int> distance(n);
    for (size_t i = 0; i < 6; i++)
        distance[i] = INT_MAX;

    g.getShortestPath(src,distance,s);

    cout<<"ans is : "<<endl;

    for (size_t i = 0; i < distance.size(); i++)
    {
        cout<<distance[i]<<" ";
    }cout<<endl;
    
    


    return 0;
}






