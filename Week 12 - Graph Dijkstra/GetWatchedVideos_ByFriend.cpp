//Problem: https://leetcode.com/problems/get-watched-videos-by-your-friends/
class Solution {
public:
    vector<int> bfs(vector<vector<int>>& friends,int id,int level){
        unordered_set<int> visited;
        queue<int> q;
        q.push(id);
        visited.insert(id);
        int stop=0;
        while(!q.empty())
        {
            if(stop == level) {
                break;
            }
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto idx = q.front();
                q.pop();
           
                for(auto& fr:friends[idx]) {
                    if(visited.count(fr)==0) {
                        q.push(fr);
                        visited.insert(fr);
                    }
                }
            }
            stop++;
        }
        vector<int> friendsResult;
        while(!q.empty())
        {
            int fr = q.front();
            q.pop();
            friendsResult.push_back(fr);
        }
        return friendsResult;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> friendsResult = bfs(friends,id,level);
        unordered_map<string,int> watched;
        for(auto& frIdx:friendsResult)
        {
            for(auto& video: watchedVideos[frIdx]){
                watched[video]++;
            }
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        for(auto& [video,count]:watched){
            pq.push({count,video});
        }
        vector<string> result;
        while(!pq.empty()){
            string video = pq.top().second;
            pq.pop();
            result.push_back(video);
        }
        return result;
    }
};