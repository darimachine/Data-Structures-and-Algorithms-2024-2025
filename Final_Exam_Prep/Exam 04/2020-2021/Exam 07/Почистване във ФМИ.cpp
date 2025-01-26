#include <bits/stdc++.h>
using namespace std;

struct Time{
    size_t time;
    int value;
    bool operator<(const Time& other) {
        if(time == other.time) {
            return value>other.value;
        }
        return time<other.time;
    }
};
int main() {
    int V,Q;
    cin>>V>>Q;
    vector<Time> times;
    for(int i=0;i<V;i++) {
        size_t start,end;
        cin>>start>>end;
        times.push_back({start,1});
        times.push_back({end,-1});
    }
    queue<int> queries;
    for(int i=0;i<Q;i++) {
        int query;
        cin>>query;
        times.push_back({query,0});
        queries.push(query);
    }
    sort(times.begin(),times.end());
    unordered_map<size_t,int> intervalCounter;
    int active=0;
    for(auto& el : times){
        size_t time= el.time;
        int value = el.value;
        active+=value;
        if(value ==0) {
            intervalCounter[time]=active;    
        }
        
    }
    while(!queries.empty()){
        int q = queries.front();
        cout<<intervalCounter[q]<<" ";
        queries.pop();
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
