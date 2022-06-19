#include<bits/stdc++.h>

bool dfsCycle(int node, vector<int> adj[], vector<int>& visited, vector<int>& DFSvisited){
    visited[node] = 1;
    DFSvisited[node] = 1;
    
    for(int it : adj[node]){
        if(!visited[it]){
            if(dfsCycle(it, adj, visited, DFSvisited))
                return true;
        }
        else if(DFSvisited[it])
            return true;
    }
    DFSvisited[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    int m = edges.size();
    vector<int> adj[n + 1];
    for(int i = 0; i < m; ++i){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    vector<int> visited(n + 1, 0);
    vector<int> DFSvisited(n + 1, 0);
    
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            if(dfsCycle(i, adj, visited, DFSvisited))
                return 1;
        }
    }
    return 0;
}
