//Problem: https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> graph(n);
        for(auto& el: flights) {
            graph[el[0]].push_back({el[1],el[2]});
        }
        q.push({0,src});
        dist[src]=0;
        int stopCounter=0;
        while(!q.empty())
        {
            if(stopCounter==k+1) break;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto [w,node] = q.front();
                q.pop();
                for(auto& [neigh,weight]: graph[node]) {
                    
                    int distance = weight+w;
                    
                    if(distance<dist[neigh]){
                        dist[neigh] = distance;
                        q.push({distance,neigh});
                    }
                }
            }
            stopCounter++;
        }
        if(dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];

    }
};