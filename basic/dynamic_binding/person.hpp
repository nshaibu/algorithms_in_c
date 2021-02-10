#ifndef PERSON_H
#define PERSON_H

#include<string>

class Person {
    public:
        Person(const std::string& name, const std::string& id_num);
        virtual ~Person() {};
        virtual void print();
        std::string getName() const { return name; };
    protected:
        std::string name;
    private:
        std::string idNum;
};

#endif
