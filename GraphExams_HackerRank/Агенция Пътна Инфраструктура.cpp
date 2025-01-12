//Problem: https://www.hackerrank.com/contests/test7-sda-soft-eng/challenges/challenge-1771/problem

#include <bits/stdc++.h>
using namespace std;
unordered_map<size_t,size_t> result;
int K;
void dfs(int start,vector<vector<pair<int,int>>>& graph,vector<bool>& visited,int depth,size_t currentSum) {
    
    if(depth==K){
        result[currentSum]++;
     
        return;    
    }
    visited[start] = true;
    
    for(auto& [neigh,w]: graph[start] ) {
        if(visited[neigh]==false){
            dfs(neigh,graph,visited,depth+1,currentSum+w);
        }
    }
    visited[start]=false;//try
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
        vector<bool> visited(V+1,false);
        dfs(i,graph,visited,0,0);
    }
    // for(auto& [key,value] : result) {
    //     cout<<key<<" "<<value<<endl;
    // }
    size_t max = 0;
    long long resultKey = -1;
    for(auto& [key,value] : result) {
            
            if(value > max) {
                //cout<<key<<" "<<value<<endl;
                max=value;
                resultKey=key;
            }
            else if(value==max){
                if( key > resultKey){
                    resultKey = key;
                }
            }
        //cout<<resultKey<<endl;
    }
    cout<<resultKey;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
