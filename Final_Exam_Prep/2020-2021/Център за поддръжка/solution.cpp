#include <bits/stdc++.h>
using namespace std;

priority_queue<size_t,vector<size_t>,greater<size_t>> pq;
void print(size_t K) {
    
    for(int k=0;k<K && !pq.empty();k++) {
        size_t time = pq.top();
        pq.pop();
        cout<<time<<" ";
    }  
}
int main() {
    
    size_t K,T,B,N;
    cin>>K>>T>>B>>N;
    size_t tCount=0;
    size_t popCount=0;
    for(size_t i=0;i<N;i++) {
        size_t number;
        cin>>number;
        pq.push(number);
        tCount++;
        if(tCount==T) {
            print(K);
            popCount++;
            tCount=0;
            if (popCount == B) {
                break;
            }
        }
    }
    while(popCount < B) {
        print(K);
        popCount++;
    }
    return 0;
}
