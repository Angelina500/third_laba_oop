#include "Triangle.h"
#include <cmath>

Point Triangle::center() const {
    Point temp;
    temp.x = (a.x + b.x + c.x) / 3;
    temp.y = (a.y + b.y + c.y) / 3;
    return temp;
}

void Triangle::print(std::ostream& os) const {
    os << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y;
}

void Triangle::read(std::istream& is) {
    is >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
}

Triangle::operator double() const {
    double a1 = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    double a2 = sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
    double a3 = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
    double p = (a1 + a2 + a3) / 2;
    return sqrt(p * (p - a1) * (p - a2) * (p - a3));
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this == &other)
        return *this;
    a = other.a;
    b = other.b;
    c = other.c;
    return *this;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this == &other)
        return *this;
    a = other.a;
    b = other.b;
    c = other.c;
    return *this;
}

bool Triangle::operator==(const Triangle& other) {
    return (a.x == other.a.x) && (a.y == other.a.y)
        && (b.x == other.b.x) && (b.y == other.b.y)
        && (c.x == other.c.x) && (c.y == other.c.y);
}