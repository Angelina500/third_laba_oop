#include "Square.h"

Point Square::center() const {
    Point temp;
    temp.x = a.x + edge / 2;
    temp.y = a.y + edge / 2;
    return temp;
}

void Square::print(std::ostream& os) const {
    os << a.x << " " << a.y << " " << edge;
}

void Square::read(std::istream& is) {
    is >> a.x >> a.y >> edge;
}

Square::operator double() const {
    return edge * edge;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this == &other)
        return *this;
    a = other.a;
    edge = other.edge;
    return *this;
}

Square& Square::operator=(const Square& other) {
    if (this == &other)
        return *this;
    a = other.a;
    edge = other.edge;
    return *this;
}

bool Square::operator==(const Square& other) {
    return (a.x == other.a.x) && (a.y == other.a.y) && (edge == other.edge);
}