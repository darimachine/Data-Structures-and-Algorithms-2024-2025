#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }


    Node* reverseHelper(Node* head) {
        Node * prev =nullptr;
        Node* curr=head;
        Node* temp = nullptr;
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reverse(int from, int to) {
        
        if(from<0 || to <0 || from>to) {
            return;
        }
        Node * prev=nullptr;
        Node * curr = head;
        for(int i=0;i<from-1;i++){
            if(!curr->next) return;
            prev=curr;
            curr=curr->next;
        }
        Node* toEnd = curr; // shte CUTNEM lista za reverse
        for(int i=from;i<to;i++) {
            if(!toEnd->next) break;
            toEnd=toEnd->next;
        }
        
        Node* saveLast=toEnd->next;
        toEnd->next = nullptr; // cutting
        if(prev) {
            prev->next = reverseHelper(curr);
        }
        else {
            head = reverseHelper(curr);
        }
    
        curr->next = saveLast; 
        if(!saveLast){
            tail = curr;
        }

    }

    void print() {
        Node* temp = head;
    
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    
        cout << endl;
    }

    ~List() {
        Node* curr = head;
        
        while(curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        
        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {
        
        string op;
        cin >> op;
        
        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }
            
        if (op == "print") {
            testList.print();
        }
            
        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }
    
    return 0;
}