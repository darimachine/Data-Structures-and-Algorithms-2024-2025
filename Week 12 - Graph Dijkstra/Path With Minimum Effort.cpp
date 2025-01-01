//Problem: https://leetcode.com/problems/path-with-minimum-effort/description/

class Solution {
    struct Cell{
        int distance;
        int row;
        int col;

        bool operator<(const Cell& other) const{
            return distance>other.distance;
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row[4] = {0,1,0,-1};
        int col[4]={1,0,-1,0};
        int rowSize = heights.size();
        int colSize=heights[0].size();
        vector<vector<int>> dist(rowSize,vector<int>(colSize,INT_MAX));
        priority_queue<Cell> pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        set<pair<int,int>> visited;
        while(!pq.empty())
        {
            auto [diff,r,c] = pq.top();
            pq.pop();
          
            if(r==rowSize-1 && c==colSize-1) {
                return diff;
            }
            for(int i=0;i<4;i++)
            {
                int rowDir = r+row[i];
                int colDir=c+col[i];
                if(rowDir<0 || colDir<0 || rowDir>=rowSize || colDir>=colSize) {
                    continue;
                }
                
                int newDiff = max(diff,abs(heights[r][c] - heights[rowDir][colDir]));
                if(newDiff<dist[rowDir][colDir]) {
                    dist[rowDir][colDir]=newDiff;
                    pq.push({newDiff,rowDir,colDir});
                }
                
            }
        }
        return -1;

    }
};