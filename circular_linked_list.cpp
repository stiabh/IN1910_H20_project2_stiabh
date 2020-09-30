#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v, Node* n) {
        val = v;
        next = n;
    }
};


class CircLinkedList {
private:
    Node* head;
    int size;

public:
    CircLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~CircLinkedList() {
        Node* current = head;
        Node* next;
        for (int i=0; i<size; i++) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void append(int val) {
        Node* current = head;
        if (size == 0) {
            head = new Node(val, head);
        } else if (size == 1) {
            current = new Node(val, head);
            head->next = current;
        } else {
            while (current->next != head) {
                current = current->next;
            }
            current->next = new Node(val, head);
        }
        size += 1;
    }

    // void print() {
    //     Node* current = head;
    //     cout << "[";
    //     while (current->next != head) {
    //         cout << current->val << ", ";
    //         current = current->next;
    //     }
    //     cout << current->val << "]" << endl;
    // }
};


int main() {
    CircLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(3);
    list.append(3);
    list.append(3);
    // list.print();
    return 0;
}