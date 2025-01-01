//Problem: https://www.hackerrank.com/contests/sda-hw-11/challenges/long-long/copy-from/1387002120

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<int> dist(n+1,INT_MIN);
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int from,to,weight;
        cin>>from>>to>>weight;
        graph[from].push_back({to,weight});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()){
        auto [weight,node] = pq.top();
        pq.pop();
        
        if(weight<dist[node]) {
            continue;
        }
        for(auto& [neigh,currWeight]:graph[node]) {
            long long distance = currWeight+dist[node];
            if(distance > dist[neigh]){
                dist[neigh] = distance;
                pq.push({distance,neigh});
            }
        }
    }

    if(dist[t] == INT_MIN) {
        cout<<-1;
    }
    else{
        cout<<dist[t];
    }
    return 0;
}
