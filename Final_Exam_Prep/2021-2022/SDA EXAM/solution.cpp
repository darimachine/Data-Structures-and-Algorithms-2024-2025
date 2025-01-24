#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> bfs(unordered_map<int,unordered_set<int>>& graph, int start,int N) {
    vector<int> dist(N+1,INT_MAX);
    queue<int> q;
    dist[start]=0;
    q.push(start);
    unordered_set<int> visited;
    visited.insert(start);
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            int node = q.front();
            q.pop();
            for(auto& el : graph[node]) {
                if(visited.count(el)==0) {
                    dist[el] = dist[node]+6;
                    q.push(el);
                    visited.insert(el);
                }    
            }
            
        }
    }
    return dist;
}
int main() {
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++) {
        unordered_map<int,unordered_set<int>> graph;
        int V,E;
        cin>>V>>E;
        for(int i=0;i<E;i++) {
            int u,v;
            cin>>u>>v;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        int start;
        cin>>start;
        vector<int> dist = bfs(graph,start,V);
        for(int i=1;i<=V;i++) {
            if(start == i) continue;
            if(dist[i]==INT_MAX) {
                cout<<-1<<" ";
            }
            else{
                cout<<dist[i]<<" ";
            }
        }
        cout<<endl;
        
    }
    return 0;
}