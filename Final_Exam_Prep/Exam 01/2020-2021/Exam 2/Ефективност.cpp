#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pair{
    double x;
    double y;
    size_t index;
    bool operator<(const Pair& other){
        double firstPairFormula = (x*x)/y;
        double secondPairFormula = (other.x*other.x)/other.y;
        if(firstPairFormula == secondPairFormula) {
            return x>other.x;
        }
        return firstPairFormula>secondPairFormula;
    }
};

int main() {
    size_t N;
    cin>>N;
    vector<Pair> pairs;
    for(size_t i=1;i<=N;i++) {
        double x,y;
        cin>>x>>y;
        pairs.push_back({x,y,i});
    }
    sort(pairs.begin(),pairs.end());
    for(size_t i=0;i<N;i++) {
        cout<<pairs[i].index<<" ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
