#pragma once
using namespace std;
#include<iostream>

struct Node {
    Node* next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void reverse()
    {
        Node* headBecomingTail = head;
        Node* current = head;
        Node* prev = nullptr;
        Node* next;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        tail = headBecomingTail;
    }
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data;
            curr = curr->next;
        }
    }

public:
    Node* head, * tail;
};

void solve(LinkedList& num1, LinkedList& num2) {
    Node* current1 = num1.head;
    Node* current2 = num2.head;

    LinkedList result;

    int carry = 0;

    while (current1 || current2 || carry)
    {

        int currSum = carry;
        if (current1)
            currSum += current1->data;
        if (current2)
            currSum += current2->data;
        int toWrite = currSum % 10;
        carry = currSum / 10;
        result.add(toWrite);
        if (current1)
            current1 = current1->next;
        if (current2)
            current2 = current2->next;
    }
    result.reverse();
    result.print();

}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    std::cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        std::cin >> digit;
        num1.add(digit);
    }

    std::cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        std::cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}