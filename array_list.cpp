#include <iostream>
using namespace std;

class ArrayList {
private:
    int *data;          // pointer
    int size;           // to be displayed to user via length()
    int capacity = 1;   // actual size of array
    const int GROWTH_FACTOR = 2;

    void resize() {
        capacity = capacity * GROWTH_FACTOR;
        int tmp* = new int[capacity];   // points to dynamic array
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;      // destroys old array
        data = tmp;
    }

public:
    // constructor
    ArrayList() {
        size = 0;                   // default size is 0, e.g. empty
        data = new int[capacity];   // allocates memory
    }

    // destructor
    ~ArrayList() {
        delete[] data;      // destroys array
    }

    // get length of array
    int length() {
        return size;
    }

    void append(int n) {
        if (size >= capacity) {
            resize();
        }
        data[size] = n;
        size += 1;
    }
};

int main() {
    ArrayList list;
    cout << list.length() << endl;
    return 0;
}