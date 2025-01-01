//Problem: https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/
// Shano reshenie!!!!! not effective :))))

class Solution {
    struct Graph{
        int x;
        int y;

        bool operator<(const Graph &other) const {
            if (x != other.x)
                return x < other.x;
            return y < other.y;
        }
    };
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        map<vector<int>,int> graph;
        Graph startG={start[0],start[1]};
        Graph targetG={target[0],target[1]};
   
        vector<Graph> nodes;
        nodes.push_back(startG);

        for(auto& el : specialRoads) {
            vector<int> key = {el[0],el[1],el[2],el[3]};
            int distance = el[4];
            if(graph.count(key)!=0) {
                graph[key] = min(graph[key],distance);
            }
            else{
                graph[key]=distance;
            } // for repetitive special roots with different cost
            
            nodes.push_back({el[0],el[1]});
            nodes.push_back({el[2],el[3]});
        }
        nodes.push_back(targetG);
        
        int size = nodes.size();
        map<Graph,int> dist;
        for(int i=0;i<size;i++) {
            Graph nodetoFill = nodes[i];
            for(int j=0;j<size;j++)
            {
                if(i==j) continue;
                Graph currNode = nodes[j];
                int distance = abs(currNode.x-nodetoFill.x) + abs(currNode.y-nodetoFill.y);
                vector<int> key = {nodetoFill.x,nodetoFill.y,currNode.x,currNode.y};
                if(graph.count(key)!=0) {
                    graph[key] = min(graph[key],distance);
                }
                else{
                    graph[key] = distance;
                }
            }

            dist[nodetoFill] = INT_MAX;
        } // Creating the graph with all Posible Paths and minimum distance!!!!

        // for(auto& [key,value] : graph){
        //     for(auto& el:key) {
        //         cout<<el<<" ";
        //     }
        //     cout<<" Value: "<<value<<endl;
        // }
        //Uncomment above to understand what i mean :)

        //normal disjka algorithm its just the name of nodes are Graph obj which is pair :)
        priority_queue<pair<int,Graph>,vector<pair<int,Graph>>,greater<pair<int,Graph>>> pq;
        pq.push({0,startG});
        dist[startG]=0;
        while(!pq.empty()){
            int cost = pq.top().first;
            Graph point = pq.top().second;
            pq.pop();
            if(cost>dist[point]){
                continue;
            }
            if(point.x == targetG.x && point.y == targetG.y) {
                return dist[point];
            }
            for(auto& neigh : nodes) {
                if(neigh.x==point.x && neigh.y==point.y) continue;
                vector<int> key = {point.x,point.y,neigh.x,neigh.y};
                int currWeight = graph[key];
                int distance = currWeight + dist[point];
                if(distance<dist[neigh]){
                    dist[neigh] = distance;
                    pq.push({distance,neigh});
                }
            }
        }
        return -1;
    }
};