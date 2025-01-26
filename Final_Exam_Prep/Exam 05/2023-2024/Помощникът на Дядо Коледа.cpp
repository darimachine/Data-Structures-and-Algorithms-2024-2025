
#include <bits/stdc++.h>
using namespace std;

struct DisjointSet{
    vector<int> parents;
    vector<int> size;
    DisjointSet(int n) {
        for(int i=0;i<n;i++){
            parents.push_back(i);
            size.push_back(1);
        }
    }
    int find(int u) {
        if(parents[u] == u) {
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
        if(size[parentU]>size[parentV]){
            swap(parentU,parentV);
        }
        parents[parentU] = parentV;
        size[parentV] += size[parentU];
        
        return true;
    }
    
};
int main() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    size_t V,E;
    cin>>V>>E;
    DisjointSet ds(V+1);
    for(int i=0;i<E;i++)
    {
        size_t start,end;
        cin>>start>>end;
        ds.unite(start,end);
    }
    size_t Q;
    cin>>Q;

    for(int i=0;i<Q;i++)
    {
        
        size_t start,end;
        cin>>start>>end;
        cout << (ds.find(start) == ds.find(end))<<" ";
    }
    
    return 0;
}
