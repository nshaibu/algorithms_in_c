#ifndef STUDENT_H
#define STUDENT_H

#include "person.hpp"

class Student : public Person {
    public:
        Student(const std::string& id_num, const std::string& name,
                 const std::string& mj, int year);
        void print();
        void changeMajor(const std::string& newMajor) { major = newMajor; };
    private:
        std::string major;
        int gradYear;
};

#endif