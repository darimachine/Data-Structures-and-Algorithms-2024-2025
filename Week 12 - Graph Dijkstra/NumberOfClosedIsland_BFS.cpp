//Problem: https://leetcode.com/problems/number-of-closed-islands/?envType=problem-list-v2&envId=2hernc7d

class Solution {

    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};

    bool bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,int i,int j,int rows,int cols) {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        bool isClosed=true;
        while(!q.empty()) {
            
                auto [r,c] = q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int newRow = row[j]+r;
                    int newCol = col[j]+c;
                   
                    if(newRow<0 || newRow>=rows || newCol>=cols || newCol<0) {
                        isClosed=false;
                        continue;
                    }
                    if(visited[newRow][newCol] || grid[newRow][newCol]==1) {
                        continue;
                    }
                    visited[newRow][newCol]=true;
                    q.push({newRow,newCol});
            }
        }
        return isClosed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols=grid[0].size();
        int counter =0;
        vector<vector<bool>> visited(rows,vector<bool>(cols));
        for(int i=0;i<rows;i++) {

            for(int j=0;j<cols;j++) {
                if(grid[i][j] == 1){
                    visited[i][j]=true;
                    continue;
                }
                if(visited[i][j]==false){
                    if(bfs(grid,visited,i,j,rows,cols)) {
                        counter++;
                    }
                }
            }
        }
        return counter;
    }
};