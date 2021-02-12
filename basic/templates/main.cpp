#include<iostream>
#include<string>
#include "basic_vector.hpp"
using namespace std;

int main(void) {
    BasicVector<int> integers(2);
    BasicVector<string> str(2);
    BasicVector<double> db(2);

    BasicVector<int> d(integers);

    integers[0] = 23;
    integers[1] = 34;

    db[0] = 23.4434;
    db[1] = 3.221232;

    BasicVector<double> vdb = db;

    str[0] = "Hello";
    str[1] = "world";

    integers.print();
    d.print();
    str.print();
    db.print();
    vdb.print();

    return 0;
}
