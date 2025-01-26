#include <bits/stdc++.h>
using namespace std;


int main() {
    unordered_map<int,int> mp;
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        int number;
        cin>>number;
        mp[number]= (mp[number]+1)%10;
        if(mp[number]==0){
            mp.erase(number);
        }
    }
    int countProduct=0;
    int countUser=0;
    for(auto& [user,product] : mp) {
        countProduct+=product;
        countUser++;
    }
    cout<<countUser<<" "<<countProduct;
  
    return 0;
}