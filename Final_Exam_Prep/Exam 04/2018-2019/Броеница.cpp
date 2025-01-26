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


	void count(Node *root) {
		queue<Node*> q;
        q.push(root);
        bool isFirstPrint=true;
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++) {
                auto node = q.front();
                q.pop();
                if(node->leftNode){
                    q.push(node->leftNode);
                }
                if(node->rightNode){
                    q.push(node->rightNode);
                }
            }
            if(isFirstPrint) {
                cout<<size;
                isFirstPrint=false;
            }
            else{
                cout<<";"<<size;
            }
        }
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
  
	myTree.count(root);
    return 0;
}