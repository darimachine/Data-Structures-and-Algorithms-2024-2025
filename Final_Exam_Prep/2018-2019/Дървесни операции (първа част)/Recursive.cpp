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

Node* insertHelper(Node* &root, int value) {
    if(root == nullptr) {
        root = new Node(value);
        return root;
    }
    if(root->data<value) {
        root->right = insertHelper(root->right,value);
    }
    else if(root->data>value) {
        root->left = insertHelper(root->left,value);
    }


    return root;
}

void add(int x){
    // or remove the & and put
    // root = insertHelper(root,x)
    insertHelper(root,x);
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
