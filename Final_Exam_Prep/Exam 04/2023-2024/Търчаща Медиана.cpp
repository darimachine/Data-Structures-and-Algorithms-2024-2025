#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

priority_queue<double> maxHeap;
priority_queue<double,vector<double>,greater<double>> minHeap;
double getMedian()
{
    if(maxHeap.size()==1 && minHeap.empty())
    {
        return maxHeap.top();
    }
    if(maxHeap.size()==minHeap.size())
    {
        int first = maxHeap.top();
        int second = minHeap.top();
        return (first+second)/2.00;
    }
    else if(maxHeap.size()>minHeap.size())
    {
        int number = maxHeap.top();
        return number;
    }
    else{
        int number = minHeap.top();
        return number;
    }
}
void add(int number)
{
    if(maxHeap.empty() && minHeap.empty())
    {
        maxHeap.push(number);
        return;
    }
    double median = getMedian();
    if(number>median)
    {
        minHeap.push(number);
    }
    else{
        maxHeap.push(number);
    }
    if(maxHeap.size()>1+minHeap.size())
    {
        int number = maxHeap.top();
        maxHeap.pop();
        minHeap.push(number);
    }
    if(minHeap.size()>1 +maxHeap.size())
    {
        int number = minHeap.top();
        minHeap.pop();
        maxHeap.push(number);
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(1); // tup hackerank
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int number;
        cin>>number;
        add(number);
        cout<<getMedian()<<endl;
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
