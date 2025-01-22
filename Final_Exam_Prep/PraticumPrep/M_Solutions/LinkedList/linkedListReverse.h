#pragma once
struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

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

    Node* reverse(Node* head)
    {
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
        return prev;
    }
    void reverse(int from, int to) {
        if (from <= 0 || to <= 0 || from > to) return;

        Node* currentToBegin = head;
        Node* prev = nullptr;

        for (int i = 1; i < from; i++) {
            if (!currentToBegin) return;
            prev = currentToBegin;
            currentToBegin = currentToBegin->next;
        }

        Node* toEnd = currentToBegin;

        for (int i = from; i < to; i++) {
            if (!toEnd->next) break;  //if we reach the end of the linked list, then no need to go further
            toEnd = toEnd->next;
        }

        Node* saveLastHead = toEnd->next;
        toEnd->next = nullptr;

        if (prev) {
            prev->next = reverse(currentToBegin);
        }
        else {
            head = reverse(currentToBegin);
        }

        currentToBegin->next = saveLastHead;

        if (!saveLastHead) {
            tail = currentToBegin;
        }
    }
};