#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    map<int,int> times;
    for(int i=0;i<N;i++) {
        size_t start,end;
        cin>>start>>end;
        if(start==end) {
            continue;
        }
        times[start] += 1;
        times[end] += -1;
    }
    int result=0;
    int currTime=0;
    for(auto& [key,value] : times){
        currTime += value;
        result=max(result,currTime);
    }
    cout<<result;
    return 0;
}
