#include<iostream>
#include "person.hpp"
#include "student.hpp"

using namespace std;


int main(void) {
    cout << "Dynamic Binding" << endl;
    Person* pp[2];
    pp[0] = new Person("1", "nafiu");
    pp[1] = new Student("2", "shaibu", "English", 2020);
    for (int i = 0; i < 2; i++) {
        pp[i]->print(); // This will resolve in type's 'print' method.
        cout << endl;
        delete pp[i];
    }
    return 0;
}
