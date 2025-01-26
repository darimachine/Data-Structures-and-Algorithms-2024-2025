#include <bits/stdc++.h>
using namespace std;


int main() {
    int N,K;
    cin>>N>>K;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<N;i++){
        int number;
        cin>>number;
        pq.push(number);
    }
    int result=0;
    while(!pq.empty() && pq.top()<K) {
        int s1 = pq.top();
        pq.pop();
        int s2;
        if(!pq.empty()) {
            s2=pq.top();
            pq.pop();
        }
        else{
            break;
        }
        int s3 = s1+2*s2;
        pq.push(s3);
        result++;
    }
    cout<< (!pq.empty()?result:-1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}