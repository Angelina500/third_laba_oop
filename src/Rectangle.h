#pragma once
#include "Figure.h"

class Rectangle : public Figure {
public:
    Point center() const override;
    void print(std::ostream&) const override;
    void read(std::istream&) override;
    operator double() const override;
    Rectangle& operator=(Rectangle&&) noexcept;
    Rectangle& operator=(const Rectangle&);
    bool operator==(const Rectangle&);

private:
    Point a;
    double edgex; 
    double edgey;
};