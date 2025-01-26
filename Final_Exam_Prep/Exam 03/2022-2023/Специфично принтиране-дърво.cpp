#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    int data;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int data): data(data) {
        
    }
};
Node* insert(Node*& root,int x){
    if(root== nullptr) {
        root = new Node(x);
        return root;
    }
    if(root->data < x) {
        root->right = insert(root->right,x);
    }
    if(root->data>x){
        root->left =insert(root->left,x);
    }
    return root;
}
bool isHaveTwoChildrens(Node * root) {
    return root->left && root->right;
}
void printTree(Node* root) {
    if(root==nullptr){
        return;
    }
    if(isHaveTwoChildrens(root)){
        cout<<root->data<<" ";
    }
    printTree(root->left);
    printTree(root->right);
}
int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        int V;
        cin>>V;
        Node* root = nullptr;
        for(int j=0;j<V;j++) {
            int number;
            cin>>number;
            insert(root,number);
        }
        printTree(root);
        cout<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
