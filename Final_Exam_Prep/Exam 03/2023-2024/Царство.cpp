#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,unordered_set<int>>& graph, int start,int& count) {
    for(auto& el : graph[start]) {
        count++;
        dfs(graph,el,count);
    }
}
int main() {
    unordered_map<int,unordered_set<int>> graph;
    int V;
    cin>>V;
    int u,v;
    while(cin>>u>>v) {
        graph[u].insert(v);
    }
    for(int i=0;i<V;i++) {
        int count=0;
        dfs(graph,i,count);
        cout<<count<<" ";
    }
    return 0;
}
