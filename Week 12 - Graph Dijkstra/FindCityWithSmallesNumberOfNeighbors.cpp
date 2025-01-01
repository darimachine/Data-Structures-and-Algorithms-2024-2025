// muchih q s nqkakuv slojen nachin 2 chasa a to izleze easy :@ :@ :@
//Problem: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
class Solution {
 
public:
    int cityWithSmallesNeighbours(unordered_map<int,int>& cities){
        pair<int,int> result;
        int min=INT_MAX;
        for(auto& [city,neighbour]:cities) {
                if(min>neighbour){
                    result = {city,neighbour};
                    min=neighbour;
                }
                else if(min==neighbour){
                    if(result.first<city){
                        result = {city,neighbour};
                    }
                }
        }
        return result.first;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,int> cities;//cityName : neighboursCount

        vector<vector<pair<int,int>>> graph(n);
        for(auto& el : edges){
            graph[el[0]].push_back({el[1],el[2]});
            graph[el[1]].push_back({el[0],el[2]});
        }
        for(int i=0;i<n;i++){

            int currentDistance=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<int> dist(n,INT_MAX);
            pq.push({0,i});
            dist[i]=0;

            cities[i]=0;
            while(!pq.empty()) {
                
                auto [weight,node] = pq.top();
                pq.pop();
                if(weight>dist[node]) {
                    continue;
                }
                
                for(auto [neighbour,currWeight]:graph[node]) {
                    int distance =dist[node]+currWeight;

                    if(distance<=dist[neighbour]) {
                        dist[neighbour] =distance;
                        pq.push({distance,neighbour});
                    }
                }
            }
            for(int j=0;j<n;j++)
            {
                if(j==i || dist[j]==INT_MAX || dist[j]>distanceThreshold) {
                    continue;
                }
                cities[i]++;
            }
        }
        return cityWithSmallesNeighbours(cities);
    }
};