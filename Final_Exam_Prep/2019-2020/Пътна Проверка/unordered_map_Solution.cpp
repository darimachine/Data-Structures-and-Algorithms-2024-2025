#include <bits/stdc++.h>
using namespace std;

int dist=0;
unordered_map<int,unordered_map<int,int>> graph;

int main() {
    int V,E;
    cin>>V>>E;
  
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    int path;
    cin>>path;
    int from;
    cin>>from;
    for(int i=1;i<path;i++){
        int to;
        cin>>to;
        if(graph[from].count(to)) {
            dist+=graph[from][to];
        }
        else{
            cout<<-1;
            return 0;
        }
        from=to;
        
    }
    cout<<dist;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
