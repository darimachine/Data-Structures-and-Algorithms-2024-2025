#include <bits/stdc++.h>
using namespace std;
struct Time{
    int start;
    int end;
    int index;
    bool operator<(const Time& other) const{
        if(start==other.start){
            return end>other.end; // nai malkite purvi
        }
        return start>other.start;
    }
};


int main() {
    priority_queue<Time> pq;
    int N,T;
    cin>>N;
    for(int i=0;i<N;i++) {
        int start,end;
        cin>>start>>end;
        pq.push({start,end,i});
    }
    
    cin>>T;
    priority_queue<int,vector<int>,greater<int>> avaibleChairs; // all the avaible chairs from [0....N]
    
    for(int i=0;i<N;i++) {
        avaibleChairs.push(i);
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> occupiedChairs;// {end,chairWhichSits}
    
    
    while(!pq.empty())
    {
        Time t = pq.top();
        pq.pop();
        while(!occupiedChairs.empty() && t.start>=occupiedChairs.top().first) {
            int freeChair = occupiedChairs.top().second; //occupied Chair goes to free chair
            avaibleChairs.push(freeChair);
            occupiedChairs.pop();
        }
        int currAvaibleChair = avaibleChairs.top();
        avaibleChairs.pop();
        if(t.index==T) {
            cout<<currAvaibleChair;
            return 0;
        }
        occupiedChairs.push({t.end,currAvaibleChair});
        
    }   
    return 0;
}