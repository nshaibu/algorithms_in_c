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
    return 0;
}
