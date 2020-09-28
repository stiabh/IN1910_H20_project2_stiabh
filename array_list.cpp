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
        int *tmp = new int[capacity];   // points to new dynamic array
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;      // destroys old array
        data = tmp;         // tmp is only defined within scope resize()
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

    // get length of list
    int length() {
        return size;
    }

    // add integer to end of list
    void append(int n) {
        if (size >= capacity) {
            resize();
        }
        data[size] = n;
        size += 1;
    }

    // pretty print list
    void print() {
        cout << "[";
        if (size != 0) {
            for (int i=0; i<size-1; i++) {
                cout << data[i] << ", ";
            }
            cout << data[size-1];
        }
        cout << "]" << endl;
    }
};

// return true if integer is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    } else {
        for (int i=2; i<n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

// test ArrayList by appending first 10 primes
void test_ArrayList() {
    ArrayList primes;
    int n = 0;
    while (primes.length() < 10) {
        if (is_prime(n) == true) {
            primes.append(n);
        }
        n += 1;
    }
    primes.print();
}

int main() {
    test_ArrayList();
    
    return 0;
}