#include <bits/stdc++.h>
using namespace std;

unordered_map<int,queue<int>> mp;
int main() {
    int N;
    cin>>N;
    vector<int> numbers(N);
    for(int i=0;i<N;i++) {
        cin>>numbers[i];
    }
    vector<int> sortedNum = vector<int>(numbers);
    sort(sortedNum.begin(),sortedNum.end());
    for(int i=0;i<N;i++) {
        mp[sortedNum[i]].push(i);
    }
    for(auto& el:numbers) {
        cout<<mp[el].front()<<" ";
        mp[el].pop();
    }

    return 0;
}
