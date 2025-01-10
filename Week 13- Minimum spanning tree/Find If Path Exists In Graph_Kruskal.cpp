//Problem : https://leetcode.com/problems/find-if-path-exists-in-graph/description/

struct DisjointSet {
        vector<int> parents;
        vector<int> size;

        DisjointSet(int n) {
            for(int i=0;i<n;i++){
                parents.push_back(i);
                size.push_back(1);
            }
        }
        int find(int v) {
            if(v==parents[v]){
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for(int i=0;i<edges.size();i++){
            int to = edges[i][0];
            int from = edges[i][1];
            ds.unite(to,from);
        }
        return ds.find(source) == ds.find(destination);
    }