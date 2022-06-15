#include<bits/stdc++.h>

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> adj[vertex + 1];
    int v = edges.size();
    for(int i = 0; i < v; ++i){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    for(int i = 0; i < vertex; ++i){
        sort(adj[i].begin(), adj[i].end());
    }
    
    vector<int> bfs;
    vector<int> visited(vertex + 1, 0);
    
    for(int i = 0; i < vertex; ++i){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            
            while(!q.empty()){
                int front = q.front();
                q.pop();
                bfs.push_back(front);
                
                for(auto it : adj[front]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}
