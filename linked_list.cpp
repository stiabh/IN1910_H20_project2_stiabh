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

    LinkedList(vector<int> vec) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        
        for (int i: vec) {
            append(i);
        }
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

    // remove value at index
    void remove(int index) {
        Node* current = get_node(index);

        if (current == head and current == tail) {
            delete current;
            head = nullptr;
            tail = nullptr;

        } else if (current == head) {
            Node* new_head = head->next;
            delete head;
            head = new_head;
            head->prev = nullptr;

        } else if (current == tail) {
            Node* new_tail = tail->prev;
            delete tail;
            tail = new_tail;
            tail->next = nullptr;

        } else {
            Node* before = current->prev;
            Node* after = current->next;
            delete current;
            before->next = after;
            after->prev = before;
        }
        size -= 1;
    }

    // remove and return last value in list
    int pop() {
        int val;
        if (tail != nullptr) {
            val = tail->val;
        }
        remove(size-1);
        return val;
    }

    // remove and return specific index
    int pop(int index) {
        int val = get_node(index)->val;
        remove(index);
        return val;
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

    // test to see if linking works properly
    void test_print_backwards() {
        Node* node = tail;
        cout << "[";
        for (int i=0; i<size-1; i++) {
            cout << node->val << ", ";
            node = node->prev;
        }
        cout << node->val << "]" << endl;
    }
};

void test_LinkedList() {
    cout << endl;

    cout << "Initializing list with vector as input:" << endl;
    LinkedList list({1, 2, 3, 4, 5, 6});
    list.print();
    cout << endl;

    cout << "Test method to confirm that backwards linking works:" << endl;
    list.test_print_backwards();
    cout << endl;

    cout << "Append works:" << endl;
    for (int i=0; i<10; i++) {
        list.append(i*2);
    }
    list.print();
    cout << "Length: " << list.length() << endl;
    cout << endl;

    cout << "Indexing works:" << endl;
    cout << "list[5] = " << list[5] << endl;
    cout << endl;

    cout << "Inserting 20 at index 8:" << endl;
    list.insert(20, 8);
    list.print();
    cout << "Length: " << list.length() << endl;
    cout << endl;

    cout << "Remove parts of list using for loop:" << endl;
    for (int i=4; i<10; i++) {
        list.remove(i);
    }
    list.print();
    cout << "Length: " << list.length() << endl;
    cout << endl;

    cout << "Pop last value:" << endl;
    cout << "list.pop() returns " << list.pop() << endl;
    list.print();

    cout << endl;
}

int main() {
    test_LinkedList();

    return 0;
}