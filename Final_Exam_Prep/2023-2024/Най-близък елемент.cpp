#include <bits/stdc++.h>
using namespace std;

//100/100
vector<int> arr;

int binarySearch(int N,int x) {
    int l=0;
    int r=N-1;
    int mid;
    while(l<=r) {
        mid = l+(r-l)/2;
        if(arr[mid]==x) {
            return mid;
        }
        if(arr[mid]<x) {
            r=mid-1;
        }
        else{
            l=mid+1;   
        }
    }
    // Celta e da se nameri na koq poziciq shte se insert-ne tova chislo
    // Sled tova proverqvame 2te mu susedni koe e po blizkoto i returnvame blizkoto
    // i v int main() prosto printime ot tova blizko edno lqvo
    if(r>=0 && r<N && l>=0 && l<N){ // ako e vuv vutreshnossta proverqvame
    
        int diffL = abs(x-arr[l]);
        int diffR = abs(x-arr[r]);
        if(diffL<diffR) {
            return l;
        }
        else{
            return r;
        }
    }
    return r; // ako e v nachaloto tova shte ide na -1 posle shte stane otricatelno i shte printira korektno
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int number;
        cin>>number;
        arr.push_back(number);
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++) {
        int check;
        cin>>check;
        int index = binarySearch(N,check)-1; // edno lqvo
        if(index<0) {
            cout<<-1;
        }
        else{
            cout<<arr[index];
        }
        cout<<endl;
    }

    return 0;
}