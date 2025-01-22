void printLeftProfile() {
        queue<Node *> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto node = q.front();
                q.pop();
                if(i==0) {
                    cout<<node->value<<" ";
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
      //TODO: implement this function
    }