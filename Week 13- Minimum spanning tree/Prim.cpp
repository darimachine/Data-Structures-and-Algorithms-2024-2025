int prims(int n, vector<vector<int>> edges, int start) {
    vector<vector<pair<int,int>>> graph(n+1);
    for(auto& edge : edges){
        int from = edge[0];
        int to=edge[1];
        int w=edge[2];
        graph[from].push_back({to,w});
        graph[to].push_back({from,w});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    unordered_set<int> visited;
    int distanceTotal=0;
    while(!pq.empty() && visited.size()<n) {
        auto[dist,node] = pq.top();
        pq.pop();
        
        if(visited.count(node)){
            continue;
        }
        visited.insert(node);
        distanceTotal+=dist;
        for(auto& [neigh,w] : graph[node]){
            if(visited.count(neigh)){
                continue;
            }
            pq.push({w,neigh});
        }
    }
    return distanceTotal;
}
