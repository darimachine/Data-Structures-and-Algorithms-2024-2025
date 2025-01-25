#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
set<int> times;

int findMostPurchasedByTime(unordered_map<int,int>& arr,int time) {
    auto itTime = times.lower_bound(time);
    // cout<<"Index: "<<distance(times.begin(),itTime)<<endl;
    if(time <*itTime) {
        if(itTime==times.begin()){
            return -1;
        }
        return *(--itTime);
    }
    else{
        return *(itTime); 
    }
}
int main() {
    int N;
    cin>>N;
    unordered_map<int,int> purchase;
    int maxTime =0;
    long long maxPair = 0;
    long long maxId = -1;
    for(int i=0;i<N;i++) {
        int id,time;
        cin>>id>>time;
          times.insert(time);
        maxTime = max(maxTime,time);
        
        mp[id]++;       
        if (mp[id] >= maxPair) {
            maxPair = mp[id];
            maxId = id;
        }
        
        purchase[time]=maxId;
    }
    
    // for (const auto& p : purchase) {
    //     cout << "Time: " << p.first << ", MostPurchased: " << p.second << endl;
    // }
   
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        int time;
        cin>>time;
        if(time>=maxTime) {
            cout<<purchase[maxTime]<<endl;
            continue;
        }
        int currTime =findMostPurchasedByTime(purchase,time);
        //cout<<"Zaqvka: "<<time<<" metod: "<<currTime<<endl;
        if(currTime==-1) {
            cout<<-1<<endl;
        }
        else{
              cout<<purchase[currTime]<<endl;
        }
        
      
    }

    return 0;
}