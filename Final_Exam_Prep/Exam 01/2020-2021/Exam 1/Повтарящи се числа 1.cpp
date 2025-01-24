#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin>>N;
    unordered_set<int> unique;
    for(int i=0;i<N;i++) {
        int number;
        cin>>number;
        unique.insert(number);
    }
    int M;
    cin>>M;
    size_t sum=0;
    for(int i=0;i<M;i++) {
        int number;
        cin>>number;
        if(unique.count(number)==1) {
            unique.erase(number);
            sum+=number;
        }
    }
    cout<<sum;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
