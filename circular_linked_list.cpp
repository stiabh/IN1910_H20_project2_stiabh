#include <iostream>
#include <stdexcept>

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

    int& operator[](int index) {
        if (size == 0) {
            throw range_error("IndexError");
        } else {
            Node* current = head;
            for (int i=0; i<index; i++) {
                current = current->next;
            }
            return current->val;
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
    for (int i=0; i<6; i++) {
        list.append(i);
    }

    for (int i=0; i<12; i++) {
        cout << list[i] << endl;
    }
    
    return 0;
}