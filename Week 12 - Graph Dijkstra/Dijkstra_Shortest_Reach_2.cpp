Problem: https://www.hackerrank.com/challenges/dijkstrashortreach/problem

//add this bullshit on the main
// std::ios::sync_with_stdio(false);
// cin.tie(nullptr);

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
        // vector<vector<pair<int,int>>> graph(n+1);
        // for(auto& el : edges)
        // {
        //     graph[el[0]].push_back({el[1],el[2]});
        //     graph[el[1]].push_back({el[0],el[2]});
        // }
        
        unordered_map<size_t,vector<pair<size_t,size_t>>> adj;
         
        for(auto& el : edges){
            adj[el[0]].push_back({el[1],el[2]});
            adj[el[1]].push_back({el[0],el[2]});
        }
        vector<size_t> dist (n+1,INT_MAX);
        priority_queue<pair<size_t,size_t>,vector<pair<size_t,size_t>>,greater<pair<size_t,size_t>>> pq;
        pq.push({0,s});
        dist[s]=0;
        while(!pq.empty()) {
            auto [weight,node] = pq.top();
            pq.pop();
            
            if(weight > dist[node]) {
                continue;
            }
            for(auto& [neighbour,currWeight] :adj[node]) {
                int distance = currWeight + dist[node];
                if(distance < dist[neighbour])
                {
                    dist[neighbour] = distance;
                    pq.push({distance,neighbour});
                }
            }
            
        }
        vector<int> result;
        for(int i=1;i<=n;i++) {
            if(i==s) continue;
            if(dist[i]==INT_MAX){
                result.push_back(-1);
            }
            else{
                result.push_back(dist[i]);
            }
        }
        return result;
}