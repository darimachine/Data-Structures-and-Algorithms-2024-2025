https://www.hackerrank.com/challenges/bfsshortreach/problem

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> adj(n+1);
    for(auto& el : edges) {
        adj[el[0]].push_back(el[1]);
        adj[el[1]].push_back(el[0]);
    }
    queue<int> q;
    q.push(s);
    vector<int> dist(n+1,-1);
    int currDist=6;
    vector<int> visited(n+1,0);
    visited[s]=1;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size; i++) {
            auto el = q.front();
            q.pop();
            for(auto& node : adj[el]) {
                if(visited[node]==0) {
                    visited[node] =1;
                    dist[node] = currDist;
                    q.push(node);
                }
            }
        }
        currDist+=6;
        
    }
    vector<int> result;
    for(int i=1;i<=n;i++) {
        if(i==s) continue;
        result.push_back(dist[i]);
    }
    return result;
}