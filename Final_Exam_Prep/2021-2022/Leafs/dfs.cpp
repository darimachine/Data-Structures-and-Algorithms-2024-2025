#include <bits/stdc++.h>
using namespace std;

unordered_map<int,unordered_set<int>> graph;
void dfs(int start,int&result,unordered_set<int>& visited){
    visited.insert(start);
    for(auto& el : graph[start]){
        if(visited.count(el)==0) {
            result+=el;
            dfs(el,result,visited);
        }
    }
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
        int result=0;
        unordered_set<int> visited;
        dfs(query,result,visited);
        cout<<result<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
