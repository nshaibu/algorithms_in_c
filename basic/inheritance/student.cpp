#include "student.hpp"
#include "student.hpp"
#include<iostream>
#include<string>

Student::Student(const std::string& id_num, const std::string& name, const std::string& mj, int year) 
:Person(name, id_num)
{
    gradYear = year;
    major = mj;
}

void Student::print() {
    Person::print();
    std::cout << "Graduation year: " << gradYear << "\n"
                << "Major: " << major << std::endl;
}
