#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include "../src/Figure.h"
#include "../src/Triangle.h"
#include "../src/Square.h"
#include "../src/Rectangle.h"

// Тесты для Triangle
TEST(TriangleTest, Center) {
    Triangle t;
    std::istringstream iss("0 0 3 0 0 4");
    iss >> t;
    Point center = t.center();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 4.0/3.0);
}

TEST(TriangleTest, Area) {
    Triangle t;
    std::istringstream iss("0 0 3 0 0 4");
    iss >> t;
    double area = static_cast<double>(t);
    EXPECT_DOUBLE_EQ(area, 6.0);
}

TEST(TriangleTest, Output) {
    Triangle t;
    std::istringstream iss("1 2 3 4 5 6");
    iss >> t;
    std::ostringstream oss;
    oss << t;
    EXPECT_EQ(oss.str(), "1 2 3 4 5 6");
}

TEST(TriangleTest, InputOutputConsistency) {
    Triangle t1, t2;
    std::istringstream iss("1.5 2.5 3.5 4.5 5.5 6.5");
    iss >> t1;
    
    std::ostringstream oss;
    oss << t1;
    
    std::istringstream iss2(oss.str());
    iss2 >> t2;
    
    EXPECT_TRUE(t1 == t2);
}

TEST(TriangleTest, Equality) {
    Triangle t1, t2;
    std::istringstream iss("1 2 3 4 5 6");
    iss >> t1;
    std::istringstream iss2("1 2 3 4 5 6");
    iss2 >> t2;
    EXPECT_TRUE(t1 == t2);
}

TEST(TriangleTest, Inequality) {
    Triangle t1, t2;
    std::istringstream iss("1 2 3 4 5 6");
    iss >> t1;
    std::istringstream iss2("1 2 3 4 5 7");
    iss2 >> t2;
    EXPECT_FALSE(t1 == t2);
}

TEST(TriangleTest, CopyAssignment) {
    Triangle t1, t2;
    std::istringstream iss("1 2 3 4 5 6");
    iss >> t1;
    t2 = t1;
    EXPECT_TRUE(t1 == t2);
}

// Тесты для Square
TEST(SquareTest, Center) {
    Square s;
    std::istringstream iss("0 0 5");
    iss >> s;
    Point center = s.center();
    EXPECT_DOUBLE_EQ(center.x, 2.5);
    EXPECT_DOUBLE_EQ(center.y, 2.5);
}

TEST(SquareTest, Area) {
    Square s;
    std::istringstream iss("0 0 5");
    iss >> s;
    double area = static_cast<double>(s);
    EXPECT_DOUBLE_EQ(area, 25.0);
}

TEST(SquareTest, Output) {
    Square s;
    std::istringstream iss("1 2 3");
    iss >> s;
    std::ostringstream oss;
    oss << s;
    EXPECT_EQ(oss.str(), "1 2 3");
}

TEST(SquareTest, InputOutputConsistency) {
    Square s1, s2;
    std::istringstream iss("1.5 2.5 3.5");
    iss >> s1;
    
    std::ostringstream oss;
    oss << s1;
    
    std::istringstream iss2(oss.str());
    iss2 >> s2;
    
    EXPECT_TRUE(s1 == s2);
}

TEST(SquareTest, Equality) {
    Square s1, s2;
    std::istringstream iss("1 2 3");
    iss >> s1;
    std::istringstream iss2("1 2 3");
    iss2 >> s2;
    EXPECT_TRUE(s1 == s2);
}

// Тесты для Rectangle
TEST(RectangleTest, Center) {
    Rectangle r;
    std::istringstream iss("0 0 4 6");
    iss >> r;
    Point center = r.center();
    EXPECT_DOUBLE_EQ(center.x, 2.0);
    EXPECT_DOUBLE_EQ(center.y, 3.0);
}

TEST(RectangleTest, Area) {
    Rectangle r;
    std::istringstream iss("0 0 4 6");
    iss >> r;
    double area = static_cast<double>(r);
    EXPECT_DOUBLE_EQ(area, 24.0);
}

TEST(RectangleTest, Output) {
    Rectangle r;
    std::istringstream iss("1 2 3 4");
    iss >> r;
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "1 2 3 4");
}

TEST(RectangleTest, InputOutputConsistency) {
    Rectangle r1, r2;
    std::istringstream iss("1.5 2.5 3.5 4.5");
    iss >> r1;
    
    std::ostringstream oss;
    oss << r1;
    
    std::istringstream iss2(oss.str());
    iss2 >> r2;
    
    EXPECT_TRUE(r1 == r2);
}

TEST(RectangleTest, Equality) {
    Rectangle r1, r2;
    std::istringstream iss("1 2 3 4");
    iss >> r1;
    std::istringstream iss2("1 2 3 4");
    iss2 >> r2;
    EXPECT_TRUE(r1 == r2);
}

// Полиморфизм тесты
TEST(PolymorphismTest, FigurePointer) {
    Figure* fig = new Triangle();
    std::istringstream iss("0 0 3 0 0 4");
    iss >> *fig;
    
    Point center = fig->center();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 4.0/3.0);
    
    double area = static_cast<double>(*fig);
    EXPECT_DOUBLE_EQ(area, 6.0);
    
    delete fig;
}

TEST(PolymorphismTest, DifferentFiguresSameInterface) {
    Figure* figures[2];
    
    figures[0] = new Triangle();
    std::istringstream iss1("0 0 3 0 0 4");
    iss1 >> *figures[0];
    
    figures[1] = new Square();
    std::istringstream iss2("0 0 2");
    iss2 >> *figures[1];
    
    Point center1 = figures[0]->center();
    Point center2 = figures[1]->center();
    
    EXPECT_DOUBLE_EQ(center1.x, 1.0);
    EXPECT_DOUBLE_EQ(center1.y, 4.0/3.0);
    EXPECT_DOUBLE_EQ(center2.x, 1.0);
    EXPECT_DOUBLE_EQ(center2.y, 1.0);
    
    delete figures[0];
    delete figures[1];
}

// Интеграционный тест
TEST(IntegrationTest, TotalArea) {
    Figure* figures[3];
    
    Triangle* t = new Triangle();
    std::istringstream iss1("0 0 3 0 0 4");
    iss1 >> *t;
    figures[0] = t;

    Square* s = new Square();
    std::istringstream iss2("0 0 2");
    iss2 >> *s;
    figures[1] = s;

    Rectangle* r = new Rectangle();
    std::istringstream iss3("0 0 3 4");
    iss3 >> *r;
    figures[2] = r;

    double total = 0;
    for (int i = 0; i < 3; i++) {
        total += static_cast<double>(*figures[i]);
    }
    
    EXPECT_DOUBLE_EQ(total, 6.0 + 4.0 + 12.0);
    
    delete figures[0];
    delete figures[1];
    delete figures[2];
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}