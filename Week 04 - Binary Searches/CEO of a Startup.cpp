#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool canBeDivided(vector<size_t> peoples,size_t K,size_t sum)
{
    size_t currentSum=0;
    size_t teams=0;
    for(auto people:peoples)
    {
        currentSum+=people;
        if(currentSum>sum)
        {
            teams++;
            currentSum=people;
        }
    }
    if(teams>=K)
    {
        return false;
    }
    return true;
}
int main() {
    size_t N,K;
    cin>>N>>K;
    vector<size_t> peoples;
    vector<size_t> teams(K);
    size_t left=0;
    size_t right=0;
    for(size_t i=0;i<N;i++)
    {
        size_t people;
        right+=people;
        cin>>people;
        
        if(left<people)
        {
            left=people; 
        }
        peoples.push_back(people);
    }
    // size_t left = *max_element(peoples.begin(),peoples.end());
    // size_t right = accumulate(peoples.begin(),peoples.end(),0);
   
    size_t answer=0;
    while(left<=right)
    {
        size_t mid = left + (right-left)/2;
        if(canBeDivided(peoples,K,mid))
        {
            answer=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<answer; 
    return 0;
}
