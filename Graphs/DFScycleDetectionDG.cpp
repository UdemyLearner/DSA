#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>


bool checkCycleDFS(int node, unordered_map<int, bool> &visited,
                   unordered_map<int, bool> &dfsVisited,
                   unordered_map<int, list<int>> &adj) {

  dfsVisited[node] = 1;
  visited[node] = 1;

  for (auto neighbour : adj[node]) {
    if (!visited[neighbour]) {
      bool cycleDetect = checkCycleDFS(neighbour, visited, dfsVisited, adj);
      if (cycleDetect)
        return true;
    } else if (dfsVisited[neighbour]) {
      return true;
    }
  }
  //
  dfsVisited[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  // creat adj
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  // dfs
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;
  for (int i = 1; i <= n; i++) {// Given : point no 4 in notes
    if (!visited[i]) {
      bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
      if (cycleFound)
        return true;
    }
  }

  return false;
}