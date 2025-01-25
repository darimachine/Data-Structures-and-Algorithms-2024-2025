#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& visited, int start,int parent) {
    visited[start]=1;
    for(auto& el:graph[start]) {
        if(el == parent){
            continue;
        }
        if(visited[el]==1) {
            return true;
        }
        if(visited[el]==0) {
            if(dfs(graph,visited,el,start)){
                return true;
            }
        }
        
    }
    
    visited[start]=2;
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++) {

        int V,E;
        cin>>V>>E;
        vector<int> visited(V,0);
        vector<vector<int>> graph(V);
        for(int j=0;j<E;j++) {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int result=0;
        for(int j=0;j<V;j++) {
            if(visited[j]==0) {
                if(dfs(graph,visited,j,-1)) {
                    result++;
                }
            }
        }
        cout<<result<<endl;        
    }


    return 0;
}