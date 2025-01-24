#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;

int main() {
    int N;
    cin>>N;
    vector<int> stikers(N);
    for(int i=0;i<N;i++) {
        cin>>stikers[i];
    }
    int result=0;
    for(int i=0;i<N;i++) {
        int wanted;
        cin>>wanted;
        mp[stikers[i]]++;
        if(mp[wanted]==0) {
            result++;
        }
        else{
            mp[wanted]--;
        }
    }
    cout<<result;
    return 0;
}