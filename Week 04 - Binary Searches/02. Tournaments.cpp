#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<size_t> peoples;
vector<pair<size_t,size_t>> tournaments;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t N, K;
    cin>>N>>K;
    
    for(size_t i=0;i<N;i++)
    {
        size_t weight;
        cin>>weight;
        peoples.push_back(weight);
    }
    sort(peoples.begin(),peoples.end());
    
    for(size_t i=0;i<K;i++)
    {
        size_t start,end;
        cin>>start>>end;
        tournaments.push_back({start,end});
    }
    
    for(size_t i=0;i<K;i++)
    {
        if(tournaments[i].first>tournaments[i].second)
        {
            cout<<0<<endl;
            continue;
        }
        auto itLow = lower_bound(peoples.begin(),peoples.end(),tournaments[i].first);
        
        auto itUpper = upper_bound(peoples.begin(),peoples.end(),tournaments[i].second);
        cout<< itUpper-itLow <<endl;
        
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
