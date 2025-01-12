//Problem: https://www.hackerrank.com/contests/sda-2022-2023-test7-123-43/challenges/shortest-tour/copy-from/1387305491

#include <bits/stdc++.h>
using namespace std;

unordered_map<int,unordered_set<int>> graph;
int totalAttraction;

int bfs(int start,unordered_set<int>& shouldNotVisit,int stopAttraction) {
    
    queue<int> q;
    unordered_set<int> visited;
    visited.insert(start);
    q.push(start);
    int dist=0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++) {
            int node = q.front();
            q.pop();
            for(auto& el : graph[node]){
                if(visited.count(el)==0) {
                    if(shouldNotVisit.count(el)==0){

                        visited.insert(el);
                        if(el==stopAttraction){
                            return dist+1;
                        }
                        q.push(el);
                    }
                }
            }
            
        }
        // or this but the above is more optimized        
        // if(el==stopAttraction){
        //     return dist;
        // }
        dist++;
        
    }
    return 0;
}
int main() {
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        graph[u].insert(v);
    }
    cin>>totalAttraction;
    vector<int> attractions;
    for(int i=0;i<totalAttraction;i++){
        int n;
        cin>>n;
        attractions.push_back(n);
    }
    unordered_set<int> shouldNotVisit;
    for(int i=1;i<totalAttraction;i++){
        shouldNotVisit.insert(attractions[i]);
    }
    int total=0;
    for(int i=0;i<totalAttraction-1;i++){
        int start = attractions[i];
        int stop = attractions[i+1];
        shouldNotVisit.erase(stop);
        total+=bfs(start,shouldNotVisit,stop);
        if(total==0) {
            cout<<-1;
            return 0;
        }
    }
    cout<<total;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}