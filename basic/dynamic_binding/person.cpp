#include "person.hpp"
#include <iostream>
#include <string>

Person::Person(const std::string& nm, const std::string& id_num) {
    name = nm;
    idNum = id_num;
}

void Person::print() {
    std::cout << "ID: " << idNum << "\n"
                << "Name: " << name << std::endl;
}
