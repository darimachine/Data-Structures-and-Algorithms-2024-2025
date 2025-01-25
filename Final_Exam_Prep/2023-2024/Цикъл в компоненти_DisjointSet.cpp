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
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++) {
        int result=0;
        int V,E;
        cin>>V>>E;
        DisjointSet ds(V);
        unordered_set<int> componentCycle;
        for(int j=0;j<E;j++) {
            int u,v;
            cin>>u>>v;
            if(!ds.unite(u,v)) {
                componentCycle.insert(ds.find(u));
            }
        }
        cout<<componentCycle.size()<<endl;        
    }


    return 0;
}