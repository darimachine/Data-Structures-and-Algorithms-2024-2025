#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    priority_queue<size_t,vector<size_t>,greater<size_t>> pq;
    int result=0;
    int start,end;
    vector<pair<int,int>> intervals;
    for(int i=0;i<N;i++) {
        cin>>start>>end;
        if(start==end) {
            continue;
        }
        intervals.push_back({start,end});
        
    }
    sort(intervals.begin(),intervals.end());
    int sizeInterval = intervals.size();
    for(int i=0;i<sizeInterval;i++) {
        int start = intervals[i].first;
        int end = intervals[i].second;
        while(!pq.empty() && start>=pq.top()){
            pq.pop();
        }
        pq.push(end);
        int size = pq.size();
        result = max(result,size);
    }
    cout<<result;

    return 0;
}
