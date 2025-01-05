//Problem: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=problem-list-v2&envId=abh0ymm2

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row[4]= {0,1,0,-1};
        int col[4]={1,0,-1,0};
        int rows=maze.size();
        int cols= maze[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int startX = entrance[0];
        int startY=entrance[1];
        q.push({startX,startY});
        visited[startX][startY] = true;
        int distance=0;
       
        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++) {
                auto [x,y] = q.front();
                q.pop();
               
                for(int j=0;j<4;j++) {
                    int newRow = row[j] + x;
                    int newCol = col[j] + y;
                    if(newRow <0 || newRow>=rows || newCol<0 || newCol>=cols ||
                    maze[newRow][newCol] == '+' || visited[newRow][newCol]) {
                        continue;
                    }
                    if((newRow == rows-1 || newCol == cols-1 || newRow==0 || newCol==0) ) {
                        return distance+1;
                    } 
                    cout<<newRow<<" "<<newCol<<endl;
                    visited[newRow][newCol]= true;
                    q.push({newRow,newCol});
                }
            }
            distance++;
        }
        return -1;
    }
};