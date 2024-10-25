#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t ternaryRec(size_t left,size_t right,size_t target,size_t depth)
{
    size_t l=left;
    size_t r=right;
    
    if(l<r)
    {
        size_t mid1= l+(r-l)/3;
        size_t mid2 = r-(r-l)/3;
       
        if(target> mid1 && target<mid2)
        {
            return depth;
        }
        if(target<=mid1)
        {
            return ternaryRec(l,mid1,target,depth+1);
        }
        else
        {
            return ternaryRec(mid2,r,target,depth+1);
        }
    }
    return depth;
}
int main() {
    
    size_t N,K;
    cin>>N>>K;
    size_t limit = pow(3,N);
    vector<size_t> v;
    for(size_t i=0;i<K;i++)
    {
        size_t number;
        cin>>number;
        v.push_back(number);
    }
    for(size_t i=0;i<K;i++)
    {
        cout<<ternaryRec(1,limit,v[i],1)<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
