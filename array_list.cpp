#include <iostream>
using namespace std;

class ArrayList {
private:
    int *data;          // pointer
    int size;           // to be displayed to user via length()
    int capacity = 1;   // actual size of array
    const int GROWTH_FACTOR = 2;

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

};

int main() {
    ArrayList list;
    cout << list.length() << endl;
    return 0;
}