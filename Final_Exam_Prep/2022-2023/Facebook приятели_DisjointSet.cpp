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
    int find(int u) {
        if(parents[u]==u) {
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
        if(size[parentU]>size[parentV]) {
            swap(parentU,parentV);
        }
        parents[parentU]= parentV;
        size[parentV] +=size[parentU];
        return true;
            
    }
};
unordered_map<int,int> mp;
int main() {
    int V,E,K;
    cin>>V>>E>>K;
    DisjointSet ds(V);
    for(int i=0;i<E;i++) {
        int u,v;
        cin>>u>>v;
        ds.unite(u,v);
    }
    for(int i=0;i<V;i++) {
        int parent = ds.find(i);
        mp[parent]++;
    }
    int result=0;
    for(auto& [key,value] : mp) {
        if(value%K==0) {
            result++;
        } 
    }
    cout<<result;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
