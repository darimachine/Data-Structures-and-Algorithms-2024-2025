//Problem: https://leetcode.com/problems/number-of-provinces/submissions/1504311478/
class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, unordered_set<int>& visited,int start) {
        queue<int> q;
        visited.insert(start);
        q.push(start);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(int i=0;i<isConnected[node].size();i++){
                if(visited.count(i)==0 && isConnected[node][i]==1){
                    q.push(i);
                    visited.insert(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size =isConnected.size();
        unordered_set<int> visited;
        int counter=0;
        for(int i=0;i<size;i++){
            if(visited.count(i)==0){
                counter++;
                bfs(isConnected,visited,i);
            }
        }
        return counter;
    }
};