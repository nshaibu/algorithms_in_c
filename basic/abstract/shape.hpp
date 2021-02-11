#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    public:
        virtual ~Shape() {}
        virtual double calculateArea() = 0;
};

#endif