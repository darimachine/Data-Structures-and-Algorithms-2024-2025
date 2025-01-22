#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int value): value(value){
        
    }
};
Node* root=nullptr;

Node* insertHelper(Node*& root, int x) {
    if(root == nullptr) {
        root = new Node(x);
        return root;
    }
    if(root->value < x){
        root->right = insertHelper(root->right,x);
    }
    else if(x<root->value) {
        root->left = insertHelper(root->left,x);
    }
    return root;
}

void add2(int x){
    insertHelper(root,x);
}

void add(int x) {

    if(root ==nullptr){
        root = new Node(x);
        return;
    }
    Node * current = root;
    while(true){
        if(x==current->value) {
            break;
        }
        if(current->value<x) {
            if(current->right) {
                current = current->right;
            }
            else{
                current->right = new Node(x);
                break;
            }
        }
        if(x<current->value) {
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
    cout<<root->value<<" ";
    print(root->left);
    print(root->right);
}
void find(Node* &current,Node* &parent,int x) {
    while(current && current->value!=x) {
        parent=current;
        if(current->value < x) {
            current = current->right;
        }
        else{
            current = current->left;
        }
    }
}
Node * findSuccesor(Node * root) {
    while(root->left) {
        root=root->left;
    }
    return root;
}
void remove(Node* &root, int x) {
    Node* parent = nullptr;
    Node* current = root;
    find(current,parent,x);
    if(current==nullptr) {
        return;
    }
    if(current->left == nullptr && current->right == nullptr){
        if(current != root){
            if(parent->left == current){
                parent->left=nullptr;
            }
            else if(parent->right == current){
                parent->right=nullptr;
            }
        } 
        else{
            root = nullptr;
        }
        delete current;
    }
    else if(current->left && current->right) {
        Node * succesor = findSuccesor(current->right);
        int value = succesor->value;
        remove(root,value);
        current->value  = value;
    }
    else{
        Node * child =  (current->left ? current->left : current->right);
        if(root!=current){
            if(parent->left == current) {
                parent->left = child;    
            }
            if(parent->right == current) {
                parent->right = child;
            }
        }
        else{
            root = child;
        }
        free(current);
    }
}


void print_odd_layers(Node* root) {
    queue<Node*> q;
    q.push(root);
    bool isEven=false;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            auto node = q.front();
             q.pop();
            if(!isEven) {
                 cout<<node->value<<" ";
            }
          
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
           
            
        }
        isEven=!isEven;
    }
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
            add2(number);
        }
        else if(s=="remove"){
            cin>>number;
            remove(root,number);
        }
        else if(s=="print"){
            print(root);
        }
        else if(s=="print_odd_layers") {
            print_odd_layers(root);
        }
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
