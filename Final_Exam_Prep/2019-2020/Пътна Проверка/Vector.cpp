#include <bits/stdc++.h>
using namespace std;


int distancee=0;
bool isValidPath(vector<vector<pair<int,int>>>& graph,int from, int to){
    for(auto& [neigh,w] : graph[from]) {
        if(neigh == to) {
            distancee+=w;
            return true;
        }
    }
    return false;
}

int main() {
    int V,E;
    cin>>V>>E;
  
    vector<vector<pair<int,int>>> graph(V);
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int path;
    cin>>path;
    int from;
    cin>>from;
    for(int i=1;i<path;i++){
        int to;
        cin>>to;
        if(!isValidPath(graph,from,to)) {
            cout<<-1;
            return 0;
        }
        from=to;
        
    }
    cout<<distancee;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
