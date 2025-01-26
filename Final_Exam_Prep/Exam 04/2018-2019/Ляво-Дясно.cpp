#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }

    int left=0;
    int right=0;
	void leftRight(Node *root) {
		count(root);
        cout<<"["<<left<<","<<right<<"]";
    }
    void count(Node* root) {
        if(root==nullptr){
            return;
        }
        if(root->leftNode){
            left++;
        }
        if(root->rightNode) {
            right++;
        }
        count(root->leftNode);
        count(root->rightNode);
    }


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leftRight(root);
    return 0;
}