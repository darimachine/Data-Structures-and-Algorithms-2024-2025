//https://www.hackerrank.com/contests/sda-hw-8-2021/challenges/fullstack-developer/copy-from/1387835031
#include <bits/stdc++.h>
using namespace std;

struct Purchase {
  
    int start;
    int duration;
    int index;
    bool operator<(const Purchase& other) const {
        return start>other.start;
    }
};
struct PurchasePq {
    int start;
    int duration;
    int index;
    bool operator<(const PurchasePq& other) const {
        if(duration==other.duration) {
            return index>other.index;
        }
        return duration>other.duration;
    }
};
int main() {

    int N;
    cin>>N;
    priority_queue<Purchase> purchase;
    
    for(int i=0;i<N;i++) {
        int start,durr;
        cin>>start>>durr;
        purchase.push({start,durr,i});
    }
    priority_queue<PurchasePq> pq;
    int time=purchase.top().start;
    while(!purchase.empty() || !pq.empty()) {
        while(!purchase.empty() && time>=purchase.top().start) {
            int start = purchase.top().start;
            int durr= purchase.top().duration;
            int index = purchase.top().index;
            pq.push({start,durr,index});
            purchase.pop();
  
        } 
        if(!pq.empty()){
            PurchasePq task = pq.top();
            pq.pop();
            
            time += task.duration;
            cout<<task.index<<" ";
        }
        else if (!purchase.empty()) {
            time = purchase.top().start;
        }
    }
 
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
