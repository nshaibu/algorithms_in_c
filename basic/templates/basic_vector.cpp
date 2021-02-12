#include<string>
#include "basic_vector.hpp"

using namespace std;

// template <typename T>
// BasicVector<T>::BasicVector(int cap) 
// :capacity(cap)
// {
//     data = new T[capacity];
// }

// template <typename T>
// BasicVector<T>::BasicVector(const BasicVector<T>& vec) {
//     capacity = vec.capacity;
//     data = new T[capacity];
//     for (int i = 0; i < capacity; i++)
//         data[i] = vec.data[i];
// }

// template <typename T>
// T& BasicVector<T>::operator[](int index) {
//     return data[index];
// }

// template <typename T>
// BasicVector<T>& BasicVector<T>::operator=(const BasicVector<T>& other){
//     if (this == &other) {
//         capacity = other.capacity;
//         delete [] data;
//         data = new T[capacity];
//         for (int i = 0; i < capacity; i++)
//             data[i] = other[i];
//     }
//     return *this;
// }

// template <typename T>
// T& BasicVector<T>::insert(int index,  T value) {
//     data[index] = value;
// }

// template <typename T>
// string BasicVector<T>::print() {
//     static string temp_str = "[ ";
//     for (int i = 0; i < capacity; i++)
//         temp_str += (static_cast<string>(data[i]) + ", ");
//     temp_str += "]";
//     return temp_str;
// }