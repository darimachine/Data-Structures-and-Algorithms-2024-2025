//Problem: https://www.hackerrank.com/contests/sda-hw-11-2024/challenges/roads-5/copy-from/1387298953

#include <bits/stdc++.h>
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
    int find(int v) {
        if(v==parents[v]){
            return v;
        }
        return parents[v] =find(parents[v]);
    }
    bool unite(int u,int v){
        int parentU = find(u);
        int parentV = find(v);
        if(parentU==parentV) {
            return false;
        }
        
        if(size[parentU]>size[parentV]) {
            swap(parentU,parentV);
        }
        parents[parentU]=parentV;
        size[parentV]+=size[parentU];
        return true;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V,E;
    cin>>V>>E;
    DisjointSet ds(V+1);
    for(int i=0;i<E;i++) {
        int v,u;
        cin>>v>>u;
        ds.unite(v,u);
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++) {
        int question,u,v;
        cin>>question>>u>>v;
        if(question==1) {
            cout<<(ds.find(u) == ds.find(v));
        }
        else if(question==2){
            ds.unite(u,v);
        }
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
