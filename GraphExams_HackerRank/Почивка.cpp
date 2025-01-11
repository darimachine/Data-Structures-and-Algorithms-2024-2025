//Problem: https://www.hackerrank.com/contests/test6-sda/challenges/challenge-1760/copy-from/1387287726

#include <bits/stdc++.h>
using namespace std;


int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<pair<int,int>>> graph(N+1);
    for(int i=0;i<M;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<int> dist(N+1,INT_MAX);
    int start;
    cin>>start;
    dist[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        auto [weight,node] = pq.top();
        pq.pop();
        if(weight>dist[node]) {
            continue;
        }
        for(auto& [neigh,currWeight] : graph[node]) {
            int distance= currWeight+dist[node];
            if(distance<dist[neigh]){
                dist[neigh]=distance;
                pq.push({distance,neigh});
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(start==i) continue;
        dist[i]!=INT_MAX?cout<<dist[i]:cout<<-1;
        cout<<" ";
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
