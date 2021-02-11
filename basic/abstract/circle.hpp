#ifndef CIRCLE_H
#define CIRCLE_H
#include<cmath>
#include "shape.hpp"

#define PI 3.143

class Circle : public Shape {
    public:
        Circle(double radius);
        ~Circle() {}
        double calculateArea() { return PI * pow(radius, 2); }
        double getRadius() const { return radius; }
    private:
        double radius;
};

#endif
