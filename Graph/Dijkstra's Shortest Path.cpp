
vector<int> dijkstra(vector<vector<int>> &edges, int V, int E, int S) {
    // Write your code here.
    vector<pair<int, int>> adj[V];
    
    for(int i = 0; i < E; ++i){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> distArr(V, INT_MAX);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    distArr[S] = 0;
    minHeap.push({0, S});
    
    while(!minHeap.empty()){
        int topNode = minHeap.top().second;
        int dist = minHeap.top().first;
        minHeap.pop();
        
        for(auto it : adj[topNode]){
            if(dist + it.second < distArr[it.first]){
                distArr[it.first] = dist + it.second;
                minHeap.push({distArr[it.first], it.first});
            }
        }
    }
    return distArr;
}
