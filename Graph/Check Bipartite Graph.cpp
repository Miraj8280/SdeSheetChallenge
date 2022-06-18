#include<bits/stdc++.h>

bool bfsBipartite(int node, vector<int> adj[], vector<int>& color){
    queue<int> q;
    color[node] = 1;
    q.push(node);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int it : adj[front]){
            if(color[it] == -1){
                color[it] = 1 - color[front];
                q.push(it);
            }
            else if(color[it] == color[front])
                return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n = edges[0].size();
    
    vector<int> adj[n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(edges[i][j] == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    
    vector<int> color(n, -1);
    
    for(int i = 0; i < n; ++i){
        if(color[i] == -1){
            if(!bfsBipartite(i, adj, color))
                return false;
        }
    }
    return true;
}
