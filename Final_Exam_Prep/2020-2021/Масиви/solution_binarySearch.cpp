#include <bits/stdc++.h>
using namespace std;


int main() {
    int N,M;
    cin>>N>>M;
    vector<int> firstArr;
    for(int i=0;i<N;i++) {
        int number;
        cin>>number;
        firstArr.push_back(number);
    }
    sort(firstArr.begin(),firstArr.end());
    for(int i=0;i<M;i++) {
        int number;
        cin>>number;
        auto lower =lower_bound(firstArr.begin(),firstArr.end(),number);
        cout<<lower-firstArr.begin()<<" ";
    }
 
    return 0;
}
