#include "Rectangle.h"

Point Rectangle::center() const {
    Point temp;
    temp.x = a.x + edgex / 2;
    temp.y = a.y + edgey / 2;
    return temp;
}

void Rectangle::print(std::ostream& os) const {
    os << a.x << " " << a.y << " " << edgex << " " << edgey;
}

void Rectangle::read(std::istream& is) {
    is >> a.x >> a.y >> edgex >> edgey;
}

Rectangle::operator double() const {
    return edgex * edgey;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this == &other)
        return *this;
    a = other.a;
    edgex = other.edgex;
    edgey = other.edgey;
    return *this;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this == &other)
        return *this;
    a = other.a;
    edgex = other.edgex;
    edgey = other.edgey;
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) {
    return (a.x == other.a.x) && (a.y == other.a.y) 
        && (edgex == other.edgex) && (edgey == other.edgey);
}