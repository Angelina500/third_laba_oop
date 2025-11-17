#pragma once
#include "Figure.h"

class Triangle : public Figure {
public:
    Point center() const override;
    void print(std::ostream&) const override;
    void read(std::istream&) override;
    operator double() const override;
    Triangle& operator=(Triangle&&) noexcept;
    Triangle& operator=(const Triangle&);
    bool operator==(const Triangle&);

private:
    Point a;
    Point b;
    Point c;
};