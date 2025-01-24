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
    void find(Node* &current, Node* &parent, int x) {
        if(current->value==x) {
            return;
        }
        while(current && current->value!=x) {
            parent=current;
            if(current->value<x) {
                current= current->right;
            }
            else {
                current=current->left;
                
            }
        }
        
    }
    Node* findSucessor(Node* root) {
        while(root->left){
            root=root->left;
        }
        return root;
    }
    void remove(int x) {
        Node * parent= nullptr;
        Node* current = root;
        find(current,parent,x);
        if(current==nullptr) {
            return;
        }
        if(current->right == nullptr && current->left == nullptr) {
            if(current != root) {
                if(parent->right==current) {
                    parent->right = nullptr;
                }
                else if(parent->left ==current) {
                    parent->left = nullptr;
                }
            }
            else{
                current=nullptr;
            }
            
            delete current;
        }
        else if(current->right && current->left) {
            Node * succesor = findSucessor(current->right);
            int value = succesor->value;
            remove(value);
            current->value = value;
        }
        else{
            Node* child = current->left ? current->left : current->right;
            if(current!=root) {
                 if(parent->right==current) {
                    parent->right = child;
                }
                else if(parent->left ==current) {
                    parent->left = child;
                }
            }
            else{
                root = child;
            }
            delete current;
        }
    }
    bool isLeaf(Node* node) {
        if(node->left || node->right) {
            return false;
        }
        return true;
    }
    vector<int> findNodesToRemove() {
        queue<Node*> q;
        q.push(root);
        vector<int> nodesToRemove;
        while(!q.empty()) {
         
            int size = q.size();
            for(int i=0;i<size;i++) {
                Node* node = q.front();
                q.pop();
                bool isRemovable=!isLeaf(node);
                
                if(node->left) {
                    q.push(node->left);
                    if(!isLeaf(node->left)){
                        isRemovable=false; // false
                    }
                   
                }
                if(node->right) {
                    q.push(node->right);
                    if(!isLeaf(node->right)){
                        isRemovable=false; // false
                    }
                }
                if(isRemovable) {
                    nodesToRemove.push_back(node->value);
                }
                
            }
        }
        return nodesToRemove;
    }
    void print(Node* root) {
        if(root == nullptr) {
            return;
        }
        print(root->left);
        cout<<root->value<<" ";
        print(root->right);
    }
    void deletePenultimateAndPrint() {
        vector<int> nodes = findNodesToRemove();
        for(auto& el :nodes) {
            remove(el);
        }
        print(root);
        
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
    tree.deletePenultimateAndPrint();
    return 0;
}