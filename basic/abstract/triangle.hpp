#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.hpp"

class  Triangle : public Shape {
    public:
        Triangle(float b, float h);
        ~Triangle() {}
        virtual double calculateArea();
    private:
        float breadth;
        float height;   
};
#endif
