//Problem: https://www.hackerrank.com/contests/sda-2020-2021-test11-43ed5rf/challenges/challenge-2805/copy-from/1387298321

#include <bits/stdc++.h>
using namespace std;


bool dfsCycle(vector<vector<int>>& graph, vector<int>& visited,int start) {
    visited[start]=1;
    
    for(auto& neigh:graph[start]) {
        if(visited[neigh]==0) {
            if(dfsCycle(graph,visited,neigh)){
                return true;
            }
        }
        if(visited[neigh]==1) {
            return true;
        }
       
    }
    visited[start] = 2;
    
    return false;
}
int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        
        size_t V,E; // vruh rebro
        cin>>V>>E;
        bool hasCycle=false;
        vector<vector<int>> graph(V+1);
        for(int j=0;j<E;j++) {
            size_t u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back(v);
        
        }
        vector<int> visited(V+1,0); // 0-default, 1-currently visited, 2-never to be visited again
        for(int j=1;j<=V;j++) {
            if(visited[j]==0) {
                if(dfsCycle(graph,visited,j)){
                    hasCycle=true;
                }
            }
        }
        cout<<hasCycle;
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
