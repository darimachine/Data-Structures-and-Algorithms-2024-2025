#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& tree, vector<int>& parent,vector<bool>& colored,int start, int&count) {
    for(auto& el : tree[start]) {
        dfs(tree,parent,colored,el,count);
    }
    if(!colored[start]) {
        colored[start] = true;

        for(auto& children: tree[parent[start]]) {
            if(!colored[children]) {
                colored[children] = true;
            }
        }
        colored[parent[start]] = true;
        colored[parent[parent[start]]]=true;
        count++;
    
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<vector<int>> tree(N);
    vector<int> parent(N);
    vector<bool> colored(N,false);
    int result=0;
    for(int i=0;i<N;i++) {
        int left,right;
        cin>>left>>right;
        if(left!=-1) {
            tree[i].push_back(left);
            parent[left] =i;
        }
        if(right!=-1) {
            tree[i].push_back(right);
            parent[right]=i;
        }
        
    }
    dfs(tree,parent,colored,0,result);
    cout<<result;

    return 0;
}