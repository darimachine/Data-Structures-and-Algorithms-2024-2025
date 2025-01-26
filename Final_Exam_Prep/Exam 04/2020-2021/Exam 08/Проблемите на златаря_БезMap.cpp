#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> arr;
bool checkTwoSum(int target,int startPointer,int endPointer) {
    while(endPointer>=2 || startPointer<endPointer) {
        
        int sum = arr[startPointer] + arr[endPointer];
        if(sum==target) {
            return true;
        }
        else if(sum>target) {
            endPointer--;
        }
        else{
            startPointer++;
        }
    }
    return false;
}
int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        int number;
        cin>>number;
        arr.push_back(number);
    }
    sort(arr.begin(),arr.end());
    for(int i=N-1;i>=2;i--) {
        if(checkTwoSum(arr[i],0,i-1)){
            cout<<"true";
            return 0;
        }
    }
    cout<<"false";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
