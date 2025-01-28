#include <bits/stdc++.h>
using namespace std;
struct DisjointSet {
  
    vector<size_t> parents;
    vector<size_t> size;
    unordered_map<int,size_t> sum; // extra
    DisjointSet(size_t n) {
        for(size_t i=0;i<n;i++) {
            parents.push_back(i);
            size.push_back(1);
        }
    }
    
    size_t find(size_t u) {
        if(parents[u]==u){
            return u;
        }
        return parents[u] = find(parents[u]);
    }
    bool unite(size_t u, size_t v,size_t w) {
        size_t parentU = find(u);
        size_t parentV = find(v);
        if(parentU==parentV) {
            return false;
        }
        if(size[parentU]>size[parentV]){
            swap(parentU,parentV);
        }
        parents[parentU] = parentV;
        size[parentV] += size[parentU];
        sum[parentV] += sum[parentU] + w;
        
        return true;
        
        
    }
};
struct Edge{
  
    size_t from;
    size_t to;
    size_t weight;
    bool operator<(const Edge& other){
        return weight<other.weight;
    }

};

DisjointSet kruskalMakeMPD(vector<vector<pair<size_t,size_t>>>& graph,vector<Edge>& edges,size_t V,size_t E) {
   
    DisjointSet ds(V);
    for(size_t i=0;i<E;i++) {
        size_t from = edges[i].from;
        size_t to = edges[i].to;
        size_t w = edges[i].weight;
        ds.unite(from,to,w);
          
    } 
    //fixing Node Parents
    for(size_t i=0;i<V;i++) {
        ds.find(i);
    }
    // for(auto& [key,value] : ds.sum){
    //     cout<<key<<" "<<value<<endl;
    // }
    //cout<<endl;
    return ds;
    
}
void countComponentsVertex(DisjointSet& ds,unordered_map<size_t,size_t>& vertexInComponent) {
    
    
    for(auto& el : ds.parents) {
        vertexInComponent[el]++;
    }
    // for(auto& [key,value]:vertexInComponent) {
    //     cout<<key<<" "<<value<<endl;
    // }
}
size_t countResult(vector<vector<pair<size_t,size_t>>>& graph,unordered_map<size_t,size_t>& vertexInComponent,size_t K,DisjointSet& ds) {
    size_t result =0;
    unordered_set<size_t> visited;
    for(auto& [vertex,numVertexInComponent] : vertexInComponent) {
        if(numVertexInComponent==1) {
            continue;
        }
        if(numVertexInComponent%K==0) {
            
            result +=ds.sum[vertex];
        }
    }
    return result;
}
int main()
{
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t T;
    cin>>T;
    for(size_t i=0;i<T;i++) {
        unordered_map<size_t,size_t> vertexInComponent;
        
        size_t V,E,K;
        cin>>V>>E>>K;
        vector<vector<pair<size_t,size_t>>> graph(V);
        vector<Edge> edges;
        for(size_t j=0;j<E;j++) {
            size_t u,v,w;
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }
        sort(edges.begin(),edges.end());
        // for(auto& el :edges){
        //     cout<<el.from<<" "<<el.to<<" "<<el.weight<<endl;
        // }
        DisjointSet ds = kruskalMakeMPD(graph,edges,V,E);
        countComponentsVertex(ds,vertexInComponent);
        cout<<countResult(graph,vertexInComponent,K,ds)<<endl;
        
    }
    

    return 0;
}