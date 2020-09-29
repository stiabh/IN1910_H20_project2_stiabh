#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(int v) {
        val = v;
        prev = nullptr;
        next = nullptr;
    }

    Node(int v, Node* p) {
        val = v;
        prev = p;
        next = nullptr;
    }

    Node(int v, Node* p, Node* n) {
        val = v;
        prev = p;
        next = n;
    }
};


class LinkedList {
private:
    Node* head;
    Node* tail;

    Node* get_node(int index) {
        if (index > length()-1) {
            throw range_error("IndexError");
        }

        Node* current = head;
        int count = 0;

        while (count < index) {
            current = current->next;
            count += 1;
        }

        return current;
    }

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    int& operator[](int index) {
        return get_node(index)->val;
    }

    // append integer to list
    void append(int val) {
        // empty list
        if (head == nullptr and tail == nullptr) {
            head = new Node(val);
            tail = head;    // head and tail point at same node
            return;
        }

        Node* prev_tail = tail;
        tail = new Node(val);

        prev_tail->next = tail;
        tail->prev = prev_tail;
    }

    // insert integer at specific index
    void insert(int val, int index) {
        Node* current = get_node(index);

        Node* prev = current->prev;
        Node* next = current->next;
        
        current = new Node(val, prev, next);

        prev->next = current;
        next->prev = current;
    }

    // return list length
    int length() {
        int length = 0;
        Node* current = head;

        while (current != nullptr) {
            length += 1;
            current = current->next;
        }

        return length;
    }

    // pretty print list
    void print() {
        // empty list
        if (head == nullptr and tail == nullptr) {
            cout << "[]" << endl;
            return;
        }

        Node* current;
        current = head;

        cout << "[";
        while (current->next != nullptr) {
            cout << current->val << ", ";
            current = current->next;
        }
        cout << tail->val << "]" << endl;
    }
};


int main() {
    LinkedList list;
    for (int i=0; i<5; i++) {
        list.append(i+3);
        list.print();
    }
    // list.append(2);
    list.insert(99, 2);
    list.print();

    // try {
    //     cout << list[2] << endl;
    // } catch (const std::range_error& e) {
    //     cout << "Out of range error" << endl;
    // }
    
    return 0;
}