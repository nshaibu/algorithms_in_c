#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.hpp"

class Rectangle : public Shape {
    public:
        Rectangle(float h, float w);
        ~Rectangle() {}
        virtual double calculateArea();
        float getHeight() const { return height; }
        float getWidth() const { return width; }
    private:
        float height;
        float width;
};

#endif