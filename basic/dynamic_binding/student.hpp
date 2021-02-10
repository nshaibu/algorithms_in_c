#ifndef STUDENT_H
#define STUDENT_H

#include "person.hpp"

class Student : public Person {
    public:
        Student(const std::string& id_num, const std::string& name,
                 const std::string& mj, int year);
        virtual ~Student() {};
        virtual void print();
        void changeMajor(const std::string& newMajor) { major = newMajor; };
    private:
        std::string major;
        int gradYear;
};

#endif