#include <bits/stdc++.h>
using namespace std;


int main() {
    priority_queue<int,vector<int>,greater<int>> pq;
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        int number;
        cin>>number;
        if(number!=-1){
            pq.push(number);
        }
        else{
            if(!pq.empty()){
                cout<<pq.top()<<" ";
                pq.pop();
            }
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}