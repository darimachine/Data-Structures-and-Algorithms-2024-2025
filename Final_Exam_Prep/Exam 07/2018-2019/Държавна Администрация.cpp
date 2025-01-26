#include <bits/stdc++.h>
using namespace std;


int main() {
    queue<int> q;
    int N;
    cin>>N;
    unordered_map<int,int> mp;
    vector<int> arr;
    for(int i=0;i<N;i++) {
        int number;
        cin>>number;
        mp[number]++;
        arr.push_back(number);
    }
    unordered_set<int> pushedToQ;
    for(int i=0;i<N;i++) {
        int curr = arr[i];
        if(pushedToQ.count(curr)) {
            continue;
        }
        if(mp[curr]>1) {
            pushedToQ.insert(curr);
            q.push(curr);
        }
        else{
            cout<<curr<<" ";
        }
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
