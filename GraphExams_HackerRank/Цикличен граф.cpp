//Problem: https://www.hackerrank.com/contests/sda-test6-2022-2023-iythgbeu3/challenges/-1-12/copy-from/1387303882

#include <bits/stdc++.h>
using namespace std;
bool dfs(int v,unordered_map<int,unordered_set<int>>& graph,vector<int>& visited) {
    visited[v]=1;
    
    for(auto& el:graph[v]) {
        if(visited[el]==1) {
            return true;
        }
        if(visited[el]==0) {
            if(dfs(el,graph,visited)){
                return true;
            }
        }
    }
    
    visited[v]=2;
    return false;
}

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        int V,E;
        cin>>V>>E;
        unordered_map<int,unordered_set<int>> graph;
        vector<int> visited(V+1,0);
        bool hasCycle=false;
        for(int i=0;i<E;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].insert(v);
        }
        for(int j=1;j<=V;j++) {
            if(visited[j]==0) {
                 if(dfs(j,graph,visited)){
                    hasCycle=true;
                }
            }
           
        }
       if(hasCycle) {
           cout<<"true";
       }
        else {
            cout<<"false";
        }
        cout<<" ";
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
