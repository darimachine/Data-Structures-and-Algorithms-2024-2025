//Problem: https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dist(n,0.0);
        vector<vector<pair<int,double>>> graph(n);

        for(int i=0; i < edges.size(); i++){
            
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>,less<pair<double,int>>> pq;
        pq.push({0.00,start_node});
        dist[start_node]=0.000;
        while(!pq.empty()) {
            auto [weight,node] = pq.top();
            pq.pop();
            
            if (dist[node]>weight) {
                continue;
            }
            for(auto [neighbour, currWeight] : graph[node]) {
                double distance;
                if(dist[node]==0) {
                    distance = currWeight;
                }
                else{
                    distance= currWeight * dist[node];
                }
                cout<<distance<<endl;
                if(distance > dist[neighbour]) {
                    dist[neighbour] = distance;
                    pq.emplace(distance,neighbour);
                }
            }
        }
       
        return dist[end_node];

    }
};