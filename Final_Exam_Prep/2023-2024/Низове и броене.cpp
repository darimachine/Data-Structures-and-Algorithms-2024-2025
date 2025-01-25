#include <bits/stdc++.h>
using namespace std;
bool canBeRemoved(unordered_map<char,int>& counter) {
    int occurencie = counter.begin()->second;
    for(auto& [c,num]:counter) {
        if(occurencie!=num) {
            return false;
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        unordered_map<char,int> counter;
        for(auto& c: s) {
            counter[c]++;
        }
        bool isRemoved=false;
        for(auto& c : s) {
            counter[c]--;
            if(counter[c]==0) {
                counter.erase(c);
            }
            if(canBeRemoved(counter)) {
                isRemoved=true;
                break;
            }
            counter[c]++;
        }
        cout<<isRemoved<<endl;
    }

    return 0;
}