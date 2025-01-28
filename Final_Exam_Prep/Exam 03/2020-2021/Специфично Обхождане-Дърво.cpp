#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB() {
        queue<Node*> q;
        q.push(root);
        vector<int> result;
        bool isRight=false;
        while(!q.empty()) {
            vector<int> levelVec;
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto node = q.front();
                q.pop();
                levelVec.push_back(node->value);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                
            }
            if(isRight) {
                reverse(levelVec.begin(),levelVec.end());
            }
            for(int i=0;i<size;i++) {
                result.push_back(levelVec[i]);
            }
            isRight=!isRight;
        }
        for(auto& el :result) {
            cout<<el<<" ";
        }
      //TODO: implement this method
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
  
    tree.printSFB();
    return 0;
}