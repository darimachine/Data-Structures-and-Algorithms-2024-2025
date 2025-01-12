//Problem: https://www.hackerrank.com/contests/6-20232024/challenges/1-579/problem

#include <bits/stdc++.h>
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
    int find(int v){
        if(v==parents[v]){
            return v;
        }
        return parents[v]= find(parents[v]);
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
        parents[parentU] = parentV;
        size[parentV]+=size[parentU];
        return true;
    }
};
int main() {
    int N;
    cin>>N;
    int components=N;
    int u,v;
    DisjointSet ds(N+1);
    while(cin>>u>>v){
        if(ds.unite(u,v)) {
            components--;
            cout<<components;
        }
        else{
            cout<<components<<" "<<"CYCLE FORMED!";
        }
        cout<<endl;
    }
    return 0;
}
