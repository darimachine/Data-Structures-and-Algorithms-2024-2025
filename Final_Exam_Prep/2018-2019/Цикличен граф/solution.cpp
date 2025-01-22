#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph,vector<int>& visited, int start) {
    visited[start] =1;
    
    for(auto& el : graph[start]) {
        if(visited[el] == 1) {
            return true;
        }
        if(visited[el] == 0) {
            if(dfs(graph,visited,el)) {
                return true;
            }
        }
        
    }
    
    visited[start]=2;
    return false;
}
int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        bool hasCycle=false;
        int V,E;
        cin>>V>>E;
        vector<vector<int>> graph(V+1);
        vector<int> visited(V+1,0);
        for(int i=0;i<E;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back(v);
        }
        
        for(int i=1;i<=V;i++) {
            if(visited[i]==0) {
                if(dfs(graph,visited,i)) {
                    hasCycle=true;
                    break;
                }
            }
        }
        cout<<(hasCycle ?"true ":"false ");
        
        
    } 
    return 0;
}
