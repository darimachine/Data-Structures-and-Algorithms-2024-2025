//Problem: https://www.hackerrank.com/contests/sda-hw-11-2021/challenges/shortest-paths-2/submissions/code/1387035422

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long MOD= 1000000007;
    long long n,m;
    cin>>n>>m;
    vector<vector<pair<long long,long long>>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        size_t from,to,w;
        cin>>from>>to>>w;
        graph[from].push_back({to,w});
    }
    vector<long long> dist(n+1,LLONG_MAX);
    vector<long long> ways(n+1,0);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    dist[1]=0;
    ways[1]=1;
   
    pq.push({0,1});
    while(!pq.empty()) {
        auto [weight,node] = pq.top();
        pq.pop();
        
        if(weight>dist[node]) {
            continue;
        }
        for(auto& [neigh,currWeight]: graph[node]) {
            long long distance = currWeight+dist[node];
            if(distance < dist[neigh]) {
                dist[neigh] = distance;
                ways[neigh] = ways[node];
                pq.push({distance,neigh});
            }
            else if(distance==dist[neigh]){
                ways[neigh] = (ways[neigh]+ways[node]) %MOD; 
            }
            
            
        }
    }
    if(dist[n]==LLONG_MAX) {
        cout<<-1<<" "<<0;
        return 0;
    }
    cout<<dist[n]<<" "<<ways[n];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}