//Problem: https://leetcode.com/problems/min-cost-to-connect-all-points/description/

class Solution {
public:
    struct Edge{
        int from;
        int to;
        int distance;
        bool operator<(const Edge& other){
            return distance<other.distance;
        }
    };
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
            return parents[v]=find(parents[v]);
        }
        bool unite(int u, int v) {
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numberOfPoints = points.size();
        vector<Edge> edges;
        for(int i=0;i<numberOfPoints;i++) {
             int xi = points[i][0];
             int yi = points[i][1];
            for(int j=i+1;j<numberOfPoints;j++){
                int xj=points[j][0];
                int yj=points[j][1];
                int distance = abs(xi-xj) + abs(yi-yj);
                edges.push_back({i,j,distance});
            }
        }
        sort(edges.begin(),edges.end());
        DisjointSet ds(numberOfPoints);
        int totalWeight = 0;
        int edgeCount=0;
        for(auto& edge : edges){
            int from = edge.from;
            int to= edge.to;
            int distance = edge.distance;
            cout<<from<<" "<<to<<" "<<distance<<endl;
            if(ds.unite(from,to)) {
                edgeCount++;
                totalWeight +=distance;
                if(edgeCount == numberOfPoints-1) {
                    return totalWeight;
                }
            }
        }
        return 0;

    }
};