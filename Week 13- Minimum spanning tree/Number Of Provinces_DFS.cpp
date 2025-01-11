//Problem: https://leetcode.com/problems/number-of-provinces/submissions/1504311478/
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,unordered_set<int>& visited,int start){
        visited.insert(start);

        for(int i=0;i<isConnected[start].size();i++){
            if(visited.count(i)==0 && isConnected[start][i]==1) {
                dfs(isConnected,visited,i);
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
                dfs(isConnected,visited,i);
            }
        }
        return counter;
    }
};