//Problem: https://www.hackerrank.com/contests/sda-hw-11-2024/challenges/2-146/copy-from/1387298831

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
    long long from;
    long long to;
    long long c1;
    long long c2;
    long long index;
    bool operator<(const Edge& other){
        if(c1==other.c1){
            return c2>other.c2;
        }
        return c1<other.c1;
    }
};
struct DisjointSet {
    vector<long long> parents;
    vector<long long> size;
    
    DisjointSet(long long n) {
        for(int i=0;i<n;i++) {
            parents.push_back(i);
            size.push_back(1);
        }
    }
    long long find(long long v) {
        if(v==parents[v]) {
            return v;
        }
        return parents[v] = find(parents[v]);
    }
    bool unite(long long u, long long v) {
        long long parentU = find(u);
        long long parentV = find(v);
        if(parentU==parentV) {
            return false;
        }
        if(size[parentU]>size[parentV]) {
            swap(parentU,parentV);
        }
        parents[parentU] = parentV;
        size[parentV] +=size[parentU];
        return true;
    }
    bool areInOneComponent(int u, int v){
        return find(v)==find(u);
    }
};
int main() {
    long long N,M;
    cin>>N>>M;
    vector<Edge> edges;
    DisjointSet ds(N+1);
    for(int i=0;i<M;i++) {
        long long u,v,c1,c2;
        cin>>u>>v>>c1>>c2;
        edges.push_back({u,v,c1,c2,i});
    }
    sort(edges.begin(),edges.end());
    int edgeCount=0;
    for(auto& edge:edges){
        long long from = edge.from;
        long long to = edge.to;
        if(ds.unite(from,to)){
            edgeCount++;
            cout<<edge.index+1<<endl;
            if(edgeCount==N-1) {
                break;
            }
        }
        
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}