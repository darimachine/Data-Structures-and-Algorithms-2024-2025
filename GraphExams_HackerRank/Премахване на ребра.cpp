//Problem : https://www.hackerrank.com/contests/test6-sda/challenges/challenge-1761/copy-from/1387299004

#include <bits/stdc++.h>
using namespace std;
int result=0;

int dfs(int start,vector<vector<int>>& graph,unordered_set<int>& visited) {
    visited.insert(start);
    
    int children=1;
    for(auto& neigh:graph[start]){
        if(visited.count(neigh)==0){
            int currentChildren = dfs(neigh,graph,visited);
            children+=currentChildren;
        }
    }
    
    if(children%2==0 &&start !=1){
        result++;
    }
    //cout<<start<<" "<<children<<endl;
    return children;
}
int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<int>> graph(N+1);
    unordered_set<int> visited;
    for(int i=0;i<M;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int counter=0;
  
    dfs(1,graph,visited);
    cout<<result;
    return 0;
}
