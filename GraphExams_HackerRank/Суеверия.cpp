
//Problem: https://www.hackerrank.com/contests/sda-2020-2021-test12-12ws4dw/challenges/challenge-2817/submissions/code/1387299293

#include <bits/stdc++.h>
using namespace std;


int main() {
    int V,E;
    cin>>V>>E;
    unordered_map<int,unordered_map<int,vector<int>>> graph;
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v].push_back(w);
    }
    unordered_set<int> specialNumbers;
    int countNumber;
    cin>>countNumber;
    for(int i=0;i<countNumber;i++) {
        int number;
        cin>>number;
        specialNumbers.insert(number);
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++) {
        int L,from,to;
        cin>>L;
        cin>>from;
        bool isPossible=false;
        for(int j=0;j<L-1;j++) {
            isPossible=false;
            cin>>to;
            for(auto weight: graph[from][to]){
                if(specialNumbers.count(weight)==0) {
                    isPossible=true;
                }
            }
            if(isPossible) {
                from =to;
            }
            else{
                for(int k=j+1;k<L-1;k++){
                    cin>>to;
                }
                break;
            }
        }
        cout<<isPossible;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
