#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct DisjointSet{
    
    vector<int> parents;
    vector<int> size;
    DisjointSet(int n) {
        for(int i=0;i<n;i++) {
            parents.push_back(i);
            size.push_back(1);
        }
    }
    int find(int u) {
        if(parents[u]==u) {
            return u;
        }
        return parents[u] = find(parents[u]);
    }
    bool unite(int u,int v) {
        int parentU = find(u);
        int parentV = find(v);
        if(parentU == parentV) {
            return false;
        }
        if(size[parentU] > size[parentV]) {
            swap(parentU,parentV);
        }
        parents[parentU] = parentV;
        size[parentV] +=size[parentU];
        return true;
    }
};
struct Edge{
    int from;
    int to;
    int weight;
    bool operator<(const Edge& other) const{
        return weight>other.weight; // maksimalno pokrivashto durvo!!!!!!
    }
};
int main() {
    int V,E;
    cin>>V>>E;
    DisjointSet ds(V);
    vector<Edge> edges;
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(),edges.end()); // sortirame rebrata po nizhodqsh red
    int result=0;
    for(int i=0;i<E;i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        int w= edges[i].weight;
        if(!ds.unite(from,to)) { // kato pochne da se obrazuva cikul smqtame
            result+=w;
        }
    }
    cout<<result;
    return 0;
}
