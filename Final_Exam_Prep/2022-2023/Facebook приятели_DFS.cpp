#include <bits/stdc++.h>
using namespace std;



void dfs(int start,vector<vector<int>>& graph, unordered_set<int>& visited,int& counter){
    
    
    visited.insert(start);
    for(auto& el: graph[start]){
        if(visited.count(el)==0) {
            dfs(el,graph,visited,++counter);
        }
    }
}

int main() {
    int V,E,K;
    cin>>V>>E>>K;
    vector<vector<int>> graph(V);
    unordered_set<int> visited;
    for(int i=0;i<E;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
         graph[v].push_back(u);
    }
    int result=0;
    for(int i=0;i<V;i++){
        if(visited.count(i)==0) {
            int counter=1;
            dfs(i,graph,visited,counter);
            if(counter%K==0) {
                result++;
            }
        }
    }
    cout<<result;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
