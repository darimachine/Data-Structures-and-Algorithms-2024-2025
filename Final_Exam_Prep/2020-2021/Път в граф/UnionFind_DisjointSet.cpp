#include <bits/stdc++.h>
using namespace std;
struct DisjointSet{
    
    vector<size_t> parents;
    vector<size_t> size;
    DisjointSet(size_t n) {
        for(size_t i=0;i<n;i++) {
            parents.push_back(i);
            size.push_back(1);
        }
    }
    size_t find(size_t u){
       if(parents[u] == u) {
           return u;
       }
      
       return parents[u] = find(parents[u]);
    }
    bool unite(size_t u,size_t v){
        size_t parentU = find(u);
        size_t parentV = find(v);
        if(parentU==parentV) {
            return false;
        }
        if(size[parentU]>size[parentV]){
            swap(parentU,parentV);
        }
        parents[parentU] = parentV;
        size[parentV]+=size[parentU];
        return true;
    }
    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    size_t V,E;
    cin>>V>>E;
    DisjointSet ds(V+1);
    for(size_t i=0;i<E;i++) {
        size_t u,v;
        cin>>u>>v;
        ds.unite(u,v);
    }
    size_t K;
    cin>>K;
    for(size_t i=0;i<K;i++) {
        size_t u,v;
        cin>>u>>v;
        cout<< (ds.find(u) == ds.find(v)) <<" ";
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}