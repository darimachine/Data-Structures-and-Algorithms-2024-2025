#include <bits/stdc++.h>
using namespace std;

unordered_map<int,unordered_set<int>> graph;
unordered_set<int> forbidden;
int bfs(int start,int end) {
    queue<int> q;
    unordered_set<int> visited;
    q.push(start);
    visited.insert(start);
    int dist=0;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            int node = q.front();
            q.pop();
            for(auto& el : graph[node]) {
                if(visited.count(el) || forbidden.count(el)) {
                    continue;
                }
                if(el == end) {
                    return dist+1;
                }
                q.push(el);
                visited.insert(el);
            }
        }
        dist++;
    }
    return dist;
}
int main() {
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    int P;
    cin>>P;
    vector<int> path(P);
    for(int i=0;i<P;i++) {
        int number;
        cin>>number;
        if(i>0) {
            forbidden.insert(number);
        }
        path[i]=number;
    }
    int K;
    cin>>K;
    for(int i=0;i<K;i++) {
        int notPass;
        cin>>notPass;
        forbidden.insert(notPass);
    }
    int from = path[0];
    int dist=0;
    for(int i=1;i<P;i++) {
        int to = path[i];
        forbidden.erase(to);
        dist+=bfs(from,to);
        from=to;
    }
    cout<<dist;
    return 0;
}
