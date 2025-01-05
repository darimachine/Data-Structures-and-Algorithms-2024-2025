//Problem : https://leetcode.com/problems/time-needed-to-inform-all-employees/description/?envType=problem-list-v2&envId=abh0ymm2


class Solution {
public:

    int result=0;
    void dfs(unordered_map<int,unordered_set<int>>& graph, vector<int>& informTime,
    unordered_set<int>& visited,int start,int sum) {
        if(visited.count(start)!=0) {
            return;
        }
        visited.insert(start);
        
        sum+=informTime[start];
        for(auto& el : graph[start]) {
            if(visited.count(el)==0) {
                dfs(graph,informTime,visited,el,sum);
            }
        }
        result = max(result,sum);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,unordered_set<int>> graph;
        for(int i=0;i<n;i++) {
            if(manager[i]==-1) {
                continue;
            }
            graph[manager[i]].insert(i);
        }
        unordered_set<int> informed;
        dfs(graph,informTime,informed,headID,0);
        return result;
    }
};