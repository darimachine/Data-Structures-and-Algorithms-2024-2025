//Problem: https://www.hackerrank.com/contests/sda-2021-2022-test-6-christmas/challenges/challenge-2351/submissions/code/1387299576

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
    int find(int v){
        if(v==parents[v]){
            return v;
        }
        return parents[v] = find(parents[v]);
    }
    bool unite(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        if(parentU==parentV){
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
int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        int X,Y;
        cin>>X>>Y;
        DisjointSet ds(X);
        for(int j=0;j<Y;j++){
            int v,u;
            cin>>v>>u;
            ds.unite(v,u);
        }
        int countComponets=0;
        unordered_set<int> checked;
        for(int i=0;i<X;i++) {
            int parent = ds.find(i);
            if(checked.count(parent)==0) {
                countComponets++;
                checked.insert(parent);
            }
        }
        cout<<countComponets<<" ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
