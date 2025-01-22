#include <bits/stdc++.h>
using namespace std;

unordered_map<int,unordered_set<int>> graph;
int dist =0;
int bfs(unordered_set<int>& forbiddenPaths,int start, int end) {
    int currDistance =0; 
    queue<int> q;
    q.push(start);
    unordered_set<int> visited;
    visited.insert(start);
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            int node = q.front();
            q.pop();
            
            for(auto& el : graph[node]) {
                if(forbiddenPaths.count(el)==1 || visited.count(el)==1) {
                    continue;
                }
                if(el == end) {
                    return currDistance+1; // more optimized
                }
                q.push(el);
                visited.insert(el);
            }
            // if(node == end) {
            //     return currDistance; // more iterations less optimized
            // }
            
        }
        currDistance++;
    }
    return -1;
}
int main() {
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].insert(v);
    }
    int K;
    cin>>K;
    vector<int> path;
    unordered_set<int> forbiddenPaths;
    for(int i=0;i<K;i++) {
        int number;
        cin>>number;
        path.push_back(number);
        if(i>0) {
            forbiddenPaths.insert(number);
        }
    }
    int from = path[0];
    for(int i=1;i<K;i++) {
        int to = path[i];
        forbiddenPaths.erase(to);
        int currDistance = bfs(forbiddenPaths,from,to);
        if(currDistance == -1) {
            cout<<-1;
            return 0;
        }
        dist+=currDistance;
        from = to;
    }
    cout<<dist;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
