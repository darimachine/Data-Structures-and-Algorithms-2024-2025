// Problem: https://www.hackerrank.com/contests/sda-test6-2022-2023-iythgbeu3/challenges/challenge-3826/problem

#include<bits/stdc++.h>
using namespace std;


int main() {
    int V,E;
    cin>>V>>E;
    unordered_map<int,unordered_map<int,int>> graph;
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = w;
        graph[v][u]=w;
    }
    int K;
    cin>>K;
    int from,to;
    cin>>from;
    bool hasPath=true;
    int totalWeight=0;
    for(int i=1;i<K;i++) {
       
        cin>>to;
        if(graph[from].count(to)==0) {
            hasPath=false;
        }
        else{
            totalWeight +=graph[from][to];
        }
        from=to;
    }
    if(hasPath) {
        cout<<totalWeight;
    }
    else{
        cout<<-1;
    }
    return 0;
}
