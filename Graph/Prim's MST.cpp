#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> parent(n + 1);
    vector<bool> mstSet(n + 1, false);
    vector<int> key(n + 1, INT_MAX);

    key[1] = 0;
    parent[1] = -1;
    minHeap.push({0, 1});
    
    while(!minHeap.empty()){
        int topNode = minHeap.top().second;
        minHeap.pop();
        mstSet[topNode] = true;

        for(auto it : adj[topNode]){
            int node = it.first;
            int weight = it.second;
            if(mstSet[node] == false && weight < key[node]){
                key[node] = weight;
                parent[node] = topNode;
                minHeap.push({key[node], node});
            }

        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i <= n; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}
