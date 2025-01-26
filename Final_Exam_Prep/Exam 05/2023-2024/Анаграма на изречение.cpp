#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++) {
        unordered_map<string,int> firstWord;
        int V,E;
        cin>>V>>E;
        bool canBeMade = true;
        for(int j=0;j<V;j++) {
            string s;
            cin>>s;
            firstWord[s]++;
        }
        for(int j=0;j<E;j++) {
            string s;
            cin>>s;
            if(firstWord[s]==0) {
                canBeMade=false;
            }
            firstWord[s]--;
        }
        if(canBeMade) {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}