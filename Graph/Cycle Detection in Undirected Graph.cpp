#include<bits/stdc++.h>

bool dfsCycle(int node, int parent, vector<int> adj[], vector<int>& visited){
    visited[node] = 1;
    
    for(int it : adj[node]){
        if(!visited[it]){
            if(dfsCycle(it, node, adj, visited)) return true;
        }
        else if(it != parent) return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n + 1];
    for(int i = 0; i < m; ++i){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> visited(n + 1, 0);
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
             if(dfsCycle(i, -1, adj, visited)) return "Yes";
        }
    }
    return "No";
}
