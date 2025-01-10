//Problem : https://leetcode.com/problems/shortest-path-in-binary-matrix/description/?envType=problem-list-v2&envId=awk2mqmm

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int directions[8][2]= {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0},
            {-1,-1},
            {-1,1},
            {1,-1},
            {1,1}
        };
        int rows=grid.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows,vector<bool>(rows,false));
        q.push({0,0});
        visited[0][0]=true;
        int distance=0;
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                auto [x,y] = q.front();
                q.pop();
                if(x==0 && y==0 && grid[x][y]==1) {
                    return -1;
                }
                if(x==rows-1 && y==rows-1) {
                    return distance+1;
                }
                for(int j=0;j<8;j++) {
                    int newRow=directions[j][0]+x;
                    int newCol=directions[j][1]+y;
                    if(newRow<0 || newRow>=rows || newCol<0 || newCol>=rows || 
                    visited[newRow][newCol] || grid[newRow][newCol]==1) {
                        continue;
                    }
                    // if(newRow==rows-1 && newCol==rows-1) {
                    //     return distance+2;
                    // }
                    visited[newRow][newCol] = true;
                    q.push({newRow,newCol});
                    cout<<newRow<<"  "<<newCol<<endl;
                }

            }
            distance++;
        }
        return -1;
    }
};