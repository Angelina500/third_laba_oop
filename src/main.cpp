#include <iostream>
#include <cmath>
struct Point {
  double x;
  double y;
};

class Figure {
  public:
    virtual Point center() const = 0;

    virtual void print(std::ostream&) const = 0;
    virtual void read(std::istream&) = 0;
    //создали метод где по референсу передали вывод потом ввод
    //по референсу значит по адресу(избежать копирования и мы его будем менять)
    virtual operator double() const = 0;

};
//std::ostream& возвращаем поток вывода
//метод печати для конкретного класса
std::ostream& operator<<(std::ostream& os, const Figure& obj)
{
    obj.print(os);
    return os; //чтобы писать цепочки как в 38 строке
}
 
std::istream& operator>>(std::istream& is, Figure& obj)
{
    obj.read(is);
    //if (/* T could not be constructed */)
        //is.setstate(std::ios::failbit);
    return is;
}







class Triangle : public Figure {
  public:
  Point center() const override;
  void print(std::ostream&) const override;
  void read(std::istream&) override;
  operator double() const override;
  Triangle& operator=(Triangle&&) noexcept; // оператор перемещения
  Triangle& operator=(const Triangle&);
  bool operator==(const Triangle&);
  private:
  Point a;
  Point b;
  Point c;
};
Point Triangle::center() const {
  Point temp1;
  temp1.x = (a.x + b.x + c.x) / 3;
  temp1.y = (a.y + b.y + c.y) / 3;
  return temp1;
}
void Triangle::print(std::ostream& os) const {
  os << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y ;
} //
void Triangle::read(std::istream& is) {
  is >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y ;
}
Triangle::operator double() const {
  //считаем 3 стороны
  double a1 = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
  double a2 = sqrt((b.x - c.x)*(b.x - c.x) + (b.y - c.y)*(b.y - c.y) );
  double a3 = sqrt((a.x - c.x)*(a.x - c.x) + (a.y - c.y)*(a.y - c.y) );
  double p = (a1 + a2 + a3) / 2;
  return sqrt((p - a1) * (p - a2) * (p - a3) * p);
}
//Triangle&& это ссылка на треугольник
//работает с временными объектами
//other это не адрес это указатель
//&other это адрес. Адрес хранит само значение, а не ссылку
Triangle& Triangle::operator=(Triangle&& other) noexcept{
    if (this == &other)
        {return *this;}
    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
    return *this;
    //скопировали три точки и вернули разыменованный объект
}
Triangle& Triangle::operator=(const Triangle& other) {
if (this == &other)
        {return *this;}
    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
    return *this;
}
 bool Triangle::operator==(const Triangle& other) {
  return (this->a.x == other.a.x) && (this->a.y == other.a.y)
&& (this->b.x == other.b.x) && (this->b.y == other.b.y)
&& (this->c.x == other.c.x) && (this->c.y == other.c.y);
 }






class Square : public Figure {
  public:
  Point center() const override;
  void print(std::ostream&) const override;
  void read(std::istream&) override;
  operator double() const override;
  Square& operator=(Square&&) noexcept; // оператор перемещения
  Square& operator=(const Square&);
  bool operator==(const Square&);
  private:
  Point a;
  double edge; 
};

Point Square::center() const {
  Point temp1;
  temp1.x = a.x + edge / 2;
  temp1.y = a.y + edge / 2;
  return temp1;
}

void Square::print(std::ostream& os) const {
  os << a.x << " " << a.y << " " << edge ;
} //
void Square::read(std::istream& is) {
  is >> a.x >> a.y >> edge;
}
Square::operator double() const {
  //считаем площадь квадрата
  return edge * edge;
}
Square& Square::operator=(Square&& other) noexcept{
    if (this == &other)
        {return *this;}
    this->a = other.a;
    this->edge = other.edge;
    return *this;
}
Square& Square::operator=(const Square& other) {
if (this == &other)
        {return *this;}
    this->a = other.a;
    this->edge = other.edge;
    return *this;
}
 bool Square::operator==(const Square& other) {
  return (this->a.x == other.a.x) && (this->a.y == other.a.y) && (this->edge == other.edge);
 }






class Rectangle : public Figure {
  public:
  Point center() const override;
  void print(std::ostream&) const override;
  void read(std::istream&) override;
  operator double() const override;
  Rectangle& operator=(Rectangle&&) noexcept; // оператор перемещения
  Rectangle& operator=(const Rectangle&);
  bool operator==(const Rectangle&);
  private:
  Point a;
  double edgex; 
  double edgey;
  //вводим в определенном порядке
};

Point Rectangle::center() const {
  Point temp1;
  temp1.x = a.x + edgex / 2;
  temp1.y = a.y + edgey / 2;
  return temp1;
}

void Rectangle::print(std::ostream& os) const {
  os << a.x << " " << a.y << " " << edgex << " " << edgey;
} //
void Rectangle::read(std::istream& is) {
  is >> a.x >> a.y >> edgex >> edgey;
}
Rectangle::operator double() const {
  //считаем площадь прямоугольника
  return edgex * edgey;
}
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept{
    if (this == &other)
        {return *this;}
    this->a = other.a;
    this->edgex = other.edgex;
    this->edgey = other.edgey;
    return *this;
}
Rectangle& Rectangle::operator=(const Rectangle& other) {
if (this == &other)
        {return *this;}
    this->a = other.a;
    this->edgex = other.edgex;
    this->edgey = other.edgey;
    return *this;
}
 bool Rectangle::operator==(const Rectangle& other) {
  return (this->a.x == other.a.x) && (this->a.y == other.a.y) 
  && (this->edgex == other.edgex) && (this->edgey == other.edgey);
 }




int main() {
  int count = 0;
  std::cin >> count;
  std::cout << count << " number of figures" << std::endl;
  Figure* fig[count]; //массив указателей
  for (int i = 0; i < count; ++i) {
    char temp;
    std::cin >> temp;
    Figure *ptr;
    //пытаемся понять, что за фигура
    switch (temp) {
      case '1': //треугольник
      ptr = new Triangle();
      std::cout << "You have chosen the triangle" << std::endl;
      break;
      case '2': //квадрат
      ptr = new Square();
      std::cout << "You have chosen the square" << std::endl;
      break;
      case '3': //прямоугольник
      ptr = new Rectangle();
      std::cout << "You have chosen the rectangle" << std::endl;
      break;
      default:std::cout << "i don't know the figure" << std::flush; exit(1);
      
    }

    
    std::cin >> *ptr; //читаем фигуру(внутри значения)
    //разыименовываем указатель, чтобы записать туда значения(внутрь фигуры)
    fig[i] = ptr;
  }
  double total_S = 0;
    for (int i = 0; i < count; ++i) {
      Point temp;
      temp = fig[i]->center(); //(*fig[i]).center()
      std::cout << temp.x << " " << temp.y << std::endl; 
      double S;
      S = static_cast<double>(*fig[i]);
      std::cout << S << std::endl;
      total_S += S;
    }//:)
    std::cout << total_S << std::endl << std::flush;
    //удаляем элемент по индексу
    std::cout << std::endl << "index delete:";
    int index = 0;
    std::cin >> index;
    delete fig[index];
    fig[index] = fig[count - 1];
    count--;
  return 0;
    
}