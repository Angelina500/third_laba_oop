#include "Figure.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Figure& obj) {
    obj.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& obj) {
    obj.read(is);
    return is;
}