#include<bits/stdc++.h>
void recurDFS(int node, unordered_map<int, list<int>>& adj, vector<int>& visited, vector<int>& dfs){
    dfs.push_back(node);
    visited[node] = 1;
    
    for(int it : adj[node]){
        if(!visited[it]){
            recurDFS(it, adj, visited, dfs);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < E; ++i){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    vector<int> visited(V, 0);
    
    for(int i = 0; i < V; ++i){
        if(!visited[i]){
            vector<int> dfs;
            
            recurDFS(i, adj, visited, dfs);
            ans.push_back(dfs);
        }
    }
    return ans;
}
