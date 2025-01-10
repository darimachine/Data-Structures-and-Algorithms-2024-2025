// Problem: https://www.hackerrank.com/contests/sda-homework-12/challenges/challenge-2801/submissions/code/1387267471



#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> parents;
    vector<int> size;
    DisjointSet(int n) {
        for(int i=0;i<n;i++) {
            parents.push_back(i);
            size.push_back(1);
        }
    }
    
    int find(int v) {
        
        if(v==parents[v]) {
            return v;
        }
        return parents[v] = find(parents[v]);
        
    }
        
    bool unite(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        
        if(parentU == parentV) {
            return false;
        }
        if(size[parentU]>size[parentV]) {
            swap(parentU,parentV);
        }
        parents[parentU]= parentV;
        size[parentV] += size[parentU];
        return true;
    }
};
int main() {
    int N,M;
    cin>>N>>M;
    if(N<=1) {
        cout<<0;
        return 0;
    }
    DisjointSet ds(N+1);
    int counter=1;
    for(int i=0;i<M;i++) {
        int v,u;
        cin>>v>>u;
        if(ds.unite(v,u)){
            counter++;
            if(counter==N) {
                cout<<i+1;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}
