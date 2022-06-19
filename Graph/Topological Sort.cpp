#include<bits/stdc++.h>
void dfsTopoSort(int node, vector<int> adj[], vector<int>& visited, stack<int>& stk){
    visited[node] = 1;
    for(int it : adj[node]){
        if(!visited[it]){
            dfsTopoSort(it, adj, visited, stk);
        }
    }
    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> adj[v];
    for(int i = 0; i < e; ++i){
        int x = edges[i][0];
        int y = edges[i][1];
        
        adj[x].push_back(y);
    }
    
    vector<int> visited(v, 0);
    stack<int> stk;
    
    for(int i = 0; i < v; ++i){
        if(!visited[i]){
            dfsTopoSort(i, adj, visited, stk);
        }
    }
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}
