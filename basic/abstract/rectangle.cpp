#include "rectangle.hpp"

Rectangle::Rectangle(float h, float w):height(h), width(w) {}

double Rectangle::calculateArea() { return static_cast<double>(height * width); }