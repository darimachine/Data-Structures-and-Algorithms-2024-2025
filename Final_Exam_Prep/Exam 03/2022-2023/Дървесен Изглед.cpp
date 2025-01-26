#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int data): data(data){
        
    }
};

Node* insert(Node*& root, int x) {
    if(root==nullptr) {
        root = new Node(x);
        return root;
    }
    if(root->data<x){
        root->right = insert(root->right,x);
    }
    else if(root->data > x) {
        root->left =insert(root->left,x);
    }
    return root;
}
void printResult(Node* root,stack<int>& leftTree, queue<int>& rightTree) {
    while(!leftTree.empty()) {
        cout<<leftTree.top()<<" ";
        leftTree.pop();
    }
    cout<<root->data<<" ";
    while(!rightTree.empty()){
        cout<<rightTree.front()<<" ";
        rightTree.pop();
    }
}
void bfs(Node* root) {
    queue<pair<Node*,int>> q;
    q.push({root,0});
    stack<int> leftTree;
    queue<int> rightTree;
    unordered_set<int> visited;
    while(!q.empty()){
        auto [node,column] = q.front();
        q.pop();
        if(column>0 && visited.count(column)==0) {
            visited.insert(column);
            rightTree.push(node->data);            
        }
        if(column<0 && visited.count(column)==0) {
            visited.insert(column);
            leftTree.push(node->data);
        }
        if(node->left) {
            q.push({node->left,column-1});
        }
        if(node->right){
            q.push({node->right,column+1});
        }
    }
    printResult(root,leftTree,rightTree);
    
}
int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        Node* root=nullptr;
        int V;
        cin>>V;
        for(int j=0;j<V;j++) {
            int node;
            cin>>node;
            insert(root,node);
        }
        bfs(root);
        cout<<endl;
    }
    
    return 0;
}
