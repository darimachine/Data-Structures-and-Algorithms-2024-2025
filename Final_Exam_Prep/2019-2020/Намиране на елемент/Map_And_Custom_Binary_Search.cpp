#include <bits/stdc++.h>
using namespace std;

unordered_map<int,pair<int,int>> mp;
int insertPosition(vector<int>& numbers,int x) {
    int l=0;
    int r=numbers.size()-1;
    while(l<=r) {
        size_t mid = l+(r-l)/2;
        if(numbers[mid]<x) {
            l=mid+1;
        }
        else{
            r=mid-1;
        }

    }
    return l;
}
int main() {
    int N;
    cin>>N;
    vector<int> numbers;
    for(int i=0;i<N;i++) {
        int number;
        cin>>number;
        numbers.push_back(number);
        if(mp.count(number)==0) {
            mp[number] = {i,i};
        }
        else{
            mp[number].second=i;
        }
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++) {
        int checkNumber;
        cin>>checkNumber;
        if(mp.count(checkNumber)==1) { // sudurja se
            cout<<mp[checkNumber].first<<" "<<mp[checkNumber].second;
        }
        else{
            cout<<insertPosition(numbers,checkNumber);
        }
        cout<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
