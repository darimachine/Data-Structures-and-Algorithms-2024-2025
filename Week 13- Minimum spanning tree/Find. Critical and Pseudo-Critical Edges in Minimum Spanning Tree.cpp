//Problem : https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
class Solution {
public:
    struct UnionFind {
        vector<int> parents;
        vector<int> size;

        UnionFind(int n){
            for(int i=0;i<n;i++){
                parents.push_back(i);
                size.push_back(1);
            }
        }
        int find(int v){
            if(v==parents[v]){
                return v;
            }
            return parents[v]=find(parents[v]);
        }
        bool unite(int u,int v){
            int parentU = find(u);
            int parentV = find(v);
            if(parentU == parentV) {
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
        int index;
        bool operator<(const Edge& other){
            return distance<other.distance;
        }
    };
    int sumOfMinSpaningTree(int n, vector<Edge>& edges,int indexToRemove,Edge inserted={0,0,0,-1}) {
        UnionFind ds(n);
        int totalSum=0;
        int edgeCount=0;
        if(inserted.index!=-1){
            if(ds.unite(inserted.from,inserted.to)){
                totalSum+=inserted.distance;
                edgeCount++;
            }
        }
        for(auto& edge : edges){
            if(edge.index==indexToRemove) continue;
            int from= edge.from;
            int to = edge.to;
            if(ds.unite(from,to)){
                totalSum+=edge.distance;
                edgeCount++;
                if(edgeCount==n-1){
                    return totalSum;
                }
            }
        }
        return totalSum;//equvalent to 0;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<Edge> myEdges;
        int size = edges.size();
        for(int i=0;i<size;i++){
            int from = edges[i][0];
            int to=edges[i][1];
            int weight = edges[i][2];
            myEdges.push_back({from,to,weight,i});
        }
        sort(myEdges.begin(),myEdges.end());

        int minimumSum = sumOfMinSpaningTree(n,myEdges,-1);
        vector<int> critical;
        vector<int> pseudoCritical;
        for(int i=0;i<size;i++) {
            int currSum = sumOfMinSpaningTree(n,myEdges,i);
            if(currSum!=minimumSum){
                critical.push_back(i);
                continue;
            }
            int from= edges[i][0];
            int to=edges[i][1];
            int w=edges[i][2];
            Edge insertEdge ={from,to,w,i};

            currSum = sumOfMinSpaningTree(n,myEdges,-1,insertEdge);
            if(currSum==minimumSum){
                pseudoCritical.push_back(i);
            }
        }
        vector<vector<int>> result;
        result.push_back(critical);
        result.push_back(pseudoCritical);
        return result;
    }
};