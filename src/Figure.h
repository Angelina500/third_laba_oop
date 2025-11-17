#pragma once
#include <iostream>

struct Point {
    double x;
    double y;
};

class Figure {
public:
    virtual Point center() const = 0;
    virtual void print(std::ostream&) const = 0;
    virtual void read(std::istream&) = 0;
    virtual operator double() const = 0;
    virtual ~Figure() = default;
};

// Объявления операторов
std::ostream& operator<<(std::ostream& os, const Figure& obj);
std::istream& operator>>(std::istream& is, Figure& obj);