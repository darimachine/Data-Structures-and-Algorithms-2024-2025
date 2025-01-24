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
        int dist;
        cin>>dist;
        vector<int> result;
        bfs(result,dist);
        for(auto& el : result) {
            cout<<el<<" ";
        }
      //TODO: implement this method
    }

private:
    void bfs(vector<int>& result,int dist) {
        queue<Node*> q;
        q.push(root);
        int currLevel =0;
        bool isIterated=false;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto node = q.front();
                q.pop();
                if(currLevel==dist) {
                    result.push_back(node->value);
                    isIterated=true;
                }
                
                if(node->right) {
                    q.push(node->right);
                }
                if(node->left) {
                    q.push(node->left);
                }
    
            }
            if(isIterated) {
                break;
            }
            currLevel++;
        }
    }
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