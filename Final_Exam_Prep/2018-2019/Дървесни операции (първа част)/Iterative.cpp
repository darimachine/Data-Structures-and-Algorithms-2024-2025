#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int data): data(data){
        
    }
};
Node* root=nullptr;

void add(int x) {

    if(root ==nullptr){
        root = new Node(x);
        return;
    }
    Node * current = root;
    while(true){
        if(x==current->data) {
            break;
        }
        if(current->data<x) {
            if(current->right) {
                current = current->right;
            }
            else{
                current->right = new Node(x);
                break;
            }
        }
        if(x<current->data) {
            if(current->left) {
                current = current->left;
            }
            else{
                current->left = new Node(x);
                break;
            }
        }
    }
    
}
void print(Node* root) {
    if(root==nullptr) {
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}


int main() {
    int N;
    cin>>N;
    string s;
    for(int i=0;i<N;i++) {
        
        int number;
        cin>>s;
        if(s=="add"){
            cin>>number;
            add(number);
        }
        else if(s=="print"){
            print(root);
        }
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
