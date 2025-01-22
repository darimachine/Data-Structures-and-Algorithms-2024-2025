
#include <bits/stdc++.h>
using namespace std;


int main() {
    map<string,int> wordsCount;
    string s;
    while(cin>>s) {
        wordsCount[s]++;
    }
    for(auto [key,value] : wordsCount) {
        if(value==1) {
            cout<<key<<endl;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
