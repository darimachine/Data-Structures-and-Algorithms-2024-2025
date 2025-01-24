#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList{
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
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
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data;
            curr = curr->next;
        }
    }
    void reverse(Node * root) {
        Node*prev = nullptr;
        Node* curr=root;
        Node* temp=nullptr;
        while(curr){
            temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        tail =head;
        head = prev;
        
    }
    Node *head, *tail;
};

void solve(LinkedList& num1, LinkedList& num2){
    
    int remainder=0;
    //stack<int> result;
    Node* head1 =num1.head;
    Node* head2 = num2.head;
    LinkedList l;
    while(head1 || head2 || remainder) {
        int sum = remainder;
        if(head1) {
            sum += head1->data;
        }
        if(head2) {
            sum+= head2->data;
        }
        int digit = sum%10;
        remainder = sum/10;
        l.add(digit);
        if(head1) {
           head1=head1->next; 
        }
        if(head2) {
           head2=head2->next;   
        }    
       
    }
    l.reverse(l.head);
    l.print();
    // while(!result.empty()) {
    //     cout<<result.top();
    //     result.pop();
    // }
}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }
    
    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }
  
    solve(num1, num2);
}