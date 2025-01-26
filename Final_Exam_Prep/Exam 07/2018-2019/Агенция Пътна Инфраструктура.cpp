#include <bits/stdc++.h>
using namespace std;
int K;

unordered_map<int,int> result;
void dfs(vector<vector<pair<int,int>>>& graph,unordered_set<int>& visited, int currLevel,int sum, int start){
    
    if(currLevel == K ) {
        result[sum]++;
        return;
    }
    visited.insert(start);
    for(auto& [neigh,w]: graph[start]) {
        if(visited.count(neigh)==0) {
            
            dfs(graph,visited,currLevel+1,sum+w,neigh);
        }
    }
    visited.erase(start); // shtoto moje da ima poveche ot 1 rebro mejdu vruh A i vruh B
    // Togava ako ne go mahnem ot visited, poveche nqma da razglejda ostanlite rebra!!!!
    
}
int main() {
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int,int>>> graph(V+1);
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
  
    cin>>K;
    for(int i=1;i<=V;i++){
        unordered_set<int> visited;
        dfs(graph,visited,0,0,i);
       
    }
    int maxDistance=-1;
    int maxValue=0;
    for(auto& [dist,value] :result) {
        if(value >maxValue) {
            maxValue=value;
            maxDistance=dist;
        }
        else if(value == maxValue) {
            maxDistance=max(maxDistance,dist);
        }
    }
    cout<<maxDistance;
    return 0;
}
