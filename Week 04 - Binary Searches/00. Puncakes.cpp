#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long N,K;
    cin>>N>>K;
    vector<long long> minutes;
    for(int i=0; i<K;i++)
    {
        long long number;
        cin>>number;
        minutes.push_back(number);
    }
    //sort(minutes.begin(),minutes.end());
    long long r = minutes[0] * N;
    long long l=1;
    long long answer=0;
    while(l<=r)
    {
        long long mid = l+(r-l)/2;
        long long sum=0;
        for(int i=0;i<K;i++)
        {
            sum+=mid/minutes[i];
        }
        if(sum>=N)
        {
            answer=mid;
            r=mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<answer;
}
