//Problem: https://leetcode.com/problems/min-cost-to-connect-all-points/
typedef pair<int,int> pii;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numberOfPoints = points.size();
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0});
        unordered_set<int> visited;
        int total =0;
        while(!pq.empty() && visited.size()<numberOfPoints){
            auto [distance,node] =pq.top();
            pq.pop();

            if(visited.count(node)!=0) {
                continue;
            }
            total+=distance;
            visited.insert(node);
            for(int i=0;i<numberOfPoints;i++) {
                if(visited.count(i)) {
                    continue;
                }
                int distance = abs(points[i][0]-points[node][0]) + abs(points[i][1]-points[node][1]);
                pq.push({distance,i});
            }
        }
        return total;
    }