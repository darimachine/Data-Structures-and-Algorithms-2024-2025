#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    unordered_set<int> window;
    int maxLength=0;
    int start =0;
    for(int i=0;i<n;i++) {
        
        while(window.count(arr[i])==1) {
            window.erase(arr[start]);
            start++;
        }
        
        window.insert(arr[i]);
        int size = window.size();
        maxLength = max(maxLength,size);
    }
    cout<<maxLength;
    return 0;
}
