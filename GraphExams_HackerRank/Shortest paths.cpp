//Problem: https://www.hackerrank.com/contests/6-20232024/challenges/shortest-paths-2/problem

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    size_t N,M;
    cin>>N>>M;
    vector<vector<pair<size_t,size_t>>> graph(N+1);
    for(int i=0;i<M;i++) {
        size_t u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    vector<size_t> dist(N+1,LLONG_MAX);
    priority_queue<pair<size_t,size_t>,vector<pair<size_t,size_t>>,greater<pair<size_t,size_t>>> pq;
    pq.push({0,1});
    dist[1]=0;
  
    vector<size_t> ways(N+1,0);
      ways[1]=1;
    while(!pq.empty()){
        auto[weight,node] = pq.top();
        pq.pop();
        if(weight>dist[node]){
            continue;
        }
        for(auto& [neigh,currWeight]:graph[node]){
            size_t distance = currWeight + dist[node];
            if(distance<dist[neigh]){
                dist[neigh]=distance;
                pq.push({distance,neigh});
                ways[neigh]=ways[node];
            }
            else if(distance==dist[neigh]) {
                ways[neigh] = (ways[neigh] +ways[node]) %MOD;
            }
        }
    }
    if(dist[N]==LLONG_MAX){
        cout<<-1<<" "<<0;
    }
    else{
        cout<<dist[N]<<" "<<ways[N];
    }
    return 0;
}
