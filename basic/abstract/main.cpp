#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

using namespace std;

int main(void) {
    Shape* shape[3];
    shape[0] = new Circle(34.2);
    shape[1] = new Rectangle(23.2, 23.1);
    shape[2] = new Triangle(23.3, 23.123);

    for (int i = 0; i < 3; i++){
        cout << "Area of shape " << i <<" : "<< shape[i]->calculateArea() << endl;
        delete shape[i];
    }
    return 0;
}