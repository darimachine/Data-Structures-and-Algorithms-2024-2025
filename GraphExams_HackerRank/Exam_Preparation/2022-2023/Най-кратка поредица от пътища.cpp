//Problem: https://www.hackerrank.com/contests/sda-exam-20222023-part-2/challenges/--152/submissions/code/1387306026

#include <bits/stdc++.h>
using namespace std;

int N,M,P,K;
unordered_map<int,unordered_set<int>> graph;
unordered_set<int> forbidden;
unordered_set<int> currNotAvaible;

int bfs(int start, int stop){
    queue<int> q;
    unordered_set<int> visited;
    visited.insert(start);
    q.push(start);
    int dist=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int node = q.front();
            q.pop();
            for(auto& el : graph[node]) {
                if(visited.count(el)!=0) {
                    continue;
                }
                if(forbidden.count(el)!=0 || currNotAvaible.count(el)!=0){
                    continue;
                }
                if(el == stop) {
                    return dist+1;
                }
                visited.insert(el);
                q.push(el);
            }
        }

        dist++;
    }
    return dist;
    
}
int main() {
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    cin>>P;
    vector<int> vertexToPass(P);
    for(int i=0;i<P;i++) {
        int v;
        cin>>v;
        vertexToPass[i] = v;
    }
    cin>>K;
    for(int i=0;i<K;i++) {
        int v;
        cin>>v;
        forbidden.insert(v);
    }
    for(int i=1;i<P;i++) {
        currNotAvaible.insert(vertexToPass[i]);
    }
    int result=0;
    for(int i=0;i<P-1;i++){
        int start= vertexToPass[i];
        int stop = vertexToPass[i+1];
        currNotAvaible.erase(stop);
        result+=bfs(start,stop);
    }
    cout<<result;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
