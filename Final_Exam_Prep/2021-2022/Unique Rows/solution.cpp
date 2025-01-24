#include <bits/stdc++.h>
using namespace std;

int main() {
    
    map<vector<int>,int> mp;
    int N,M;
    cin>>N>>M;
 
    for(int i=0;i<N;i++) {
        vector<int> arr;
        for(int j=0;j<M;j++) {
            int number;
            cin>>number;
            arr.push_back(number);
        }
        mp[arr]++;
    }
    int counter=0;
    for(auto& [key,value]:mp) {
        if(value==1) {
            counter++;
        }
    }
    cout<<counter;
    return 0;
}