#include <bits/stdc++.h>
using namespace std;

unordered_map<int,unordered_set<int>> graph;
int bfs(int start) {
    queue<int> q;
    q.push(start);
    unordered_set<int> visited;
    visited.insert(start);
    int result=0;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            int node = q.front();
            q.pop();
            for(auto& el :graph[node]) {
                if(visited.count(el)==0) {
                    q.push(el);
                    result+=el;
                }
            }
        }
    }
    return result;
}
int main() {
    int E,Q;
    cin>>E>>Q;
    for(int i=0;i<E;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].insert(v);
    }
    for(int i=0;i<Q;i++) {
        int query;
        cin>>query;
        cout<<bfs(query)<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
