//Problem: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& el : times){
            graph[el[0]].push_back({el[1],el[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.emplace(0,k);
        dist[k]=0;
        while(!pq.empty()) {
            auto [weight,node] = pq.top();
            pq.pop();
            if(weight>dist[node]) {
                continue;
            }
            for(auto& [neigh,currWeight] : graph[node]){
                int distance = dist[node] + currWeight;
                if(distance < dist[neigh]) {
                    dist[neigh] = distance;
                    pq.emplace(currWeight,neigh);
                }
            }
        }
        if(find(dist.begin(),dist.end(),INT_MAX)!=dist.end()){
            return -1;
        }
        return *max_element(dist.begin(),dist.end());
    }
};