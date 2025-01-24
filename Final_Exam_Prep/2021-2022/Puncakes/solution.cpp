
#include <bits/stdc++.h>
using namespace std;
size_t findCurrentTimePancakes(size_t time,const vector<size_t>& cookers) {
    size_t size = cookers.size();
    size_t result = 0;
    for(size_t i=0;i<size;i++) {
        result = result +(time/cookers[i]);
    }
    return result;
}
size_t binarySearch(size_t l,size_t r,size_t N,const vector<size_t>& cookers) {
    size_t minResult=INT_MAX;
    while(l<=r) {
        size_t mid = l+(r-l)/2;
        size_t pancakes = findCurrentTimePancakes(mid,cookers);
        if(pancakes<N) {
            l=mid+1;
        }
        else{
            minResult = mid;
            r=mid-1;
        }
    }
    return minResult;
    
}
int main() {
    size_t N,K;
    cin>>N>>K;
    vector<size_t> cookers(K);
    for(size_t i=0;i<K;i++) {
        cin>>cookers[i];
    }
    sort(cookers.begin(),cookers.end());
    size_t fastestCooker = cookers[0]; 
    //fastestCooker*N is the maximum time we need to cook the needed pancakes
    cout<<binarySearch(fastestCooker,fastestCooker*N,N,cookers);
    
    
    return 0;
}