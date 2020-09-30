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
    int size;

    // get index of node
    Node* get_node(int index) {
        if (index < 0 or index >= size) {
            throw range_error("IndexError");
        }

        Node* current = head;
        for (int i=0; i<index; i++) {
            current = current->next;
        }

        return current;
    }

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
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

    // override square-brackets operator
    int& operator[](int index) {
        return get_node(index)->val;
    }

    // insert integer at specific index
    void insert(int val, int index) {
        if (index == 0) {
            push_front(val);
        } else if (index == size) {
            append(val);
        } else {
            Node* current = get_node(index-1);
            Node* after = current->next;
            current->next = new Node(val, current, after);
            after->prev = current->next;
            size += 1;
        }
    }

    // push integer to front of list
    void push_front(int val) {
        if (head == nullptr and tail == nullptr) {
            head = new Node(val);
            tail = head;    // head and tail point at same node
        } else {
            Node* old_head = head;
            head = new Node(val, nullptr, old_head);
            old_head->prev = head;
        }
        size += 1;
    }

    // append integer to list
    void append(int val) {
        if (head == nullptr and tail == nullptr) {
            head = new Node(val);
            tail = head;    // head and tail point at same node
        } else {
            Node* old_tail = tail;
            tail = new Node(val, old_tail, nullptr);
            old_tail->next = tail;
        }        
        size += 1;
    }

    // return list length
    int length() {
        return size;
    }

    // pretty print list
    void print() {
        // empty list
        if (head == nullptr and tail == nullptr) {
            cout << "[]" << endl;
        } else {
            Node* current = head;

            cout << "[";
            while (current->next != nullptr) {
                cout << current->val << ", ";
                current = current->next;
            }
            cout << tail->val << "]" << endl;
        }
    }

    void test_backwards() {
        Node* node = tail;
        for (int i=0; i<size; i++) {
            cout << node->val << endl;
            node = node->prev;
        }
    }
};


int main() {
    LinkedList list;
    for (int i=0; i<10; i++) {
        list.append(i);
    }
    list.print();
    cout << list.length() << endl;

    return 0;
}