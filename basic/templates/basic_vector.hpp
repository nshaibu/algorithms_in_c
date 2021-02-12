#ifndef BASIC_VECTOR_H
#define BASIC_VECTOR_H
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class BasicVector {
    public:
        BasicVector(int cap) {
            capacity = cap;
            data = new T[capacity];
        }

        BasicVector(const BasicVector<T>& other) {
            capacity = other.size();
            data = new T[capacity];
            for (int i = 0; i < capacity; i++)
                data[i] = other[i];
        }

        ~BasicVector() { delete [] data; }
        
        void print() {
            for (int i = 0; i < capacity; i++)
                cout << data[i] << ", ";
            cout << endl;
        }
        
        T& operator[](int index) const { return data[index]; }
        
        BasicVector<T>& operator=(const BasicVector<T>& other) {
            if (this == &other) {
                capacity = other.size();
                delete [] data;
                data = new T[capacity];
                for (int i = 0; i < capacity; i++)
                    data[i] = other[i];
            }
            return this;
        }

        int size() const { return capacity; }
    private:
        int capacity;
        T *data;
};
#endif
