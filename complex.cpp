#include <iostream>
#include "complex.h"

figure::figure(double x, double y, double side)
        : x(x), y(y), side(side) {}

double figure::area() const {
    return side * side;
}

void figure::scale(double scale) {
    side *= scale;
}

void figure::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void figure::koord()  {
    std::cout << "( " << x << " " << y << " )";
}

bool figure::operator==(const figure& other) const {
    return area() == other.area();
}

bool figure::operator!=(const figure& other) const {
    return area() != other.area();
}

bool figure::operator<(const figure& other) const {
    return area() < other.area();
}

bool figure::operator>(const figure& other) const {
    return area() > other.area();
}