#include<iostream>
#include "person.hpp"
#include "student.hpp"

using namespace std;


int main(void) {
    cout << "Working with Person class: " << endl;
    Person p("nafiu", "1");
    p.print();
    cout << "=================================" << endl;
    cout << "Working with Student class: " << endl;
    Student s("2", "shaibu", "CS", 2018);
    s.print();

    cout << endl << endl;
    cout << "=================================" << endl;
    cout << "Static Binding" << endl;
    Person* pp[2];
    pp[0] = new Person("1", "nafiu");
    pp[1] = new Student("2", "shaibu", "English", 2020);
    for (int i = 0; i < 2; i++) {
        pp[i]->print(); // This will always use Person::print no matter the  type.
        delete pp[i];
    }
    return 0;
}
