#include<iostream>
#include "person.hpp"
#include "student.hpp"

using namespace std;


int main(void) {
    cout << "Dynamic Binding" << endl;
    Person* pp[2];
    Student* sp;
    pp[0] = new Person("nafiu", "1");
    pp[1] = new Student("2", "shaibu", "English", 2020);

    cout << "Dynamic Casting" << endl;
    for  (int i = 0; i < 2; i++) {
        sp = dynamic_cast<Student*>(pp[i]);
        if (sp != nullptr) 
            sp->changeMajor("CS");
    }

    for (int i = 0; i < 2; i++) {
        pp[i]->print(); // This will resolve in type's 'print' method.
        cout << endl;
        delete pp[i];
    }
    return 0;
}
