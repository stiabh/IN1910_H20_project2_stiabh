#include <iostream>
using namespace std;


struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int v) {
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int length() {
        int length = 0;
        Node* current = head;

        while (current != nullptr) {
            length += 1;
            current = current->next;
        }
        return length;
    }
};


int main() {
    return 0;
}