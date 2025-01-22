#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> numbers;
    for(int i=0;i<N;i++) {
        int number;
        cin>>number;
        numbers.push_back(number);
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++) {
        int checkNumber;
        cin>>checkNumber;
        auto lower = lower_bound(numbers.begin(),numbers.end(),checkNumber);
        if(*lower != checkNumber) {
            cout<<lower-numbers.begin();
        }
        else{
            auto upperIt = upper_bound(numbers.begin(),numbers.end(),checkNumber);
            cout<< lower-numbers.begin() <<" "<<upperIt-numbers.begin()-1;
        }
        cout<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}