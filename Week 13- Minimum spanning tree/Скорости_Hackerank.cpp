//Problem: https://www.hackerrank.com/contests/sda-homework-12/challenges/challenge-2799/copy-from/1387272619

#include <bits/stdc++.h>
using namespace std;

struct Edge{
    size_t from;
    size_t to;
    size_t distance;
    bool operator<(const Edge& other){
        return distance<other.distance;
    }
};
struct DisjointSet {
    vector<size_t> parents;
    vector<size_t> size;
    DisjointSet(size_t n) {
        for(int i=0;i<n;i++) {
            parents.push_back(i);
            size.push_back(1);
        }
    }
    int find(size_t v){
        if(v==parents[v]){
            return v;
        }
        return parents[v] = find(parents[v]);
    }
    bool unite(size_t u,size_t v) {
        size_t parentU = find(u);
        size_t parentV = find(v);
        if(parentU == parentV) {
            return false;
        }
        if(size[parentU]>size[parentV]) {
            swap(parentU,parentV);
        }
        
        parents[parentU] = parentV;
        size[parentV] += size[parentU];
        return true;
    }
    bool areInOneComponent(int v,int u) {
        return find(v)==find(u);
    }
};
int main() {
      size_t N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (size_t i = 0; i < M; ++i) {
        size_t u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Initialize pointers and variables
    int edgeIdxMax = 0;
    int edgeIdxMin = 0;
    size_t min = edges[edgeIdxMin].distance;
    size_t max = min;

    size_t bestMin = 0;
    size_t bestMax = INT_MAX;
    
    while (edgeIdxMax < edges.size()) {
        DisjointSet ds(N + 1);
        size_t edgeCount = 0;
        bool canMakeMST = false;
       
        for (const auto &edge : edges) {
            int weight=edge.distance;
            int from = edge.from;
            int to = edge.to;
            if (weight >= min && weight <= max) {
                if (ds.unite(from, to)) {
                    edgeCount++;
                    if (edgeCount == N - 1) { // MST is complete
                        canMakeMST = true;
                        break;
                    }
                }
            }
        }

        if (canMakeMST) {

            if ((max - min < bestMax - bestMin)) {
                bestMin = min;
                bestMax = max;
            }
            edgeIdxMin++;
            min = edges[edgeIdxMin].distance;
             
        } 
        else {
            edgeIdxMax++;
            max = edges[edgeIdxMax].distance;
        }
    }

    cout << bestMin << " " << bestMax << endl;
    return 0;
}
