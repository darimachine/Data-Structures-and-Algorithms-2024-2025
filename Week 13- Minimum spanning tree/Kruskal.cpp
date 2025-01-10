
struct DisjointSet {
    vector<int> size;
    vector<int> parents;
    
    DisjointSet(int n) {
        for(int i=0;i<n;i++) {
            parents.push_back(i);
            size.push_back(1);
        }
    }
    
    int find(int v) {
        if (v== parents[v]) {
            return v;
        }
        return parents[v] = find(parents[v]);
    }
    bool unite(int u,int v) {
        int parentU = find(u);
        int parentV = find(v);
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
struct Edge{
    int from;
    int to;
    int distance;
    
    bool operator<(const Edge& other){
        return distance < other.distance;
    }
};
int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<Edge> edges;
    int size = g_from.size();
    for(int i=0;i<size;i++){
        int from = g_from[i];
        int to=g_to[i];
        int weight = g_weight[i];
        edges.push_back({from,to,weight});
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(g_nodes+1);
    int totalWeight =0;
    int edgeCount=0;
    for(auto& edge: edges){
        if(ds.unite(edge.from,edge.to)) {
            totalWeight+=edge.distance;
            edgeCount++;
            if(edgeCount==g_nodes-1) {
                return totalWeight;
            }
        }
    }
    return -1;
}