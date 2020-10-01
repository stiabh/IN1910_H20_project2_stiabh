#include <iostream>
#include <vector>
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

    CircLinkedList(int n) {
        head = nullptr;
        size = 0;
        for (int i=1; i<=n; i++) {
            append(i);
        }
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

    void print() {
        if (size == 0) {
            cout << "[]" << endl;
        } else {
            Node* current = head;
            cout << "[";
            for (int i=0; i<size; i++) {
                cout << current->val << ", ";
                current = current->next;
            }
            cout << "...]" << endl;
        }
    }

    vector<int> josephus_sequence(int k) {
        vector<int> removed_values;
        Node* current = head;
        int i = 1;

        while (size != 0) {
            // cout << current->val << endl;
            if (i % (k-1) == 0) {
                Node* removed = current->next;
                Node* after_removed = removed->next;
                current->next = after_removed;
                removed_values.push_back(removed->val);
                // cout << "*" << removed->val << endl;
                delete removed;
                size -= 1;
            }
            current = current->next;
            i += 1;
        }
        return removed_values;
    }
};

void print_vector(vector<int> vec) {
    int n = vec.size();
    cout << "[";
    for (int i=0; i<n-1; i++) {
        cout << vec[i] << ", ";
    }
    cout << vec[n-1] << "]" << endl;
}

int last_man_standing(int n, int k) {
    CircLinkedList list(n);
    vector<int> vec = list.josephus_sequence(k);
    return vec[vec.size()-1];
}


int main() {
    cout << last_man_standing(6, 3) << endl;

    return 0;
}