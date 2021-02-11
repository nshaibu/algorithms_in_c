#include "triangle.hpp"

Triangle::Triangle(float b, float h):breadth(b), height(h) {}

double Triangle::calculateArea() { return static_cast<double>(0.5 * breadth * height); }