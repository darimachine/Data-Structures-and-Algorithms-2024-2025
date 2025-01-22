#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct DisjointSet{
    vector<int> size;
    vector<int> parents;
    
    DisjointSet(int n) {
        for(int i=0;i<n;i++) {
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
        if(parentU==parentV){
            return false;
        }
        if(size[parentU]>size[parentV]){
            swap(parentU,parentV);
        }
        parents[parentU] = parentV;
        size[parentV]+=size[parentU];
        return true;
    }
    bool areOnTheSameSet(int u,int v){
        return find(u)==find(v);
    }
};

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        int N,E;
        cin>>N>>E;
        DisjointSet ds(N);
        int components = N;
        for(int i=0;i<E;i++) {
            int u,v;
            cin>>u>>v;
            if(ds.unite(u,v)) {
                components--;
            }
        }
        cout<<components<<" ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
