#pragma once
#include "Figure.h"

class Square : public Figure {
public:
    Point center() const override;
    void print(std::ostream&) const override;
    void read(std::istream&) override;
    operator double() const override;
    Square& operator=(Square&&) noexcept;
    Square& operator=(const Square&);
    bool operator==(const Square&);

private:
    Point a;
    double edge; 
};