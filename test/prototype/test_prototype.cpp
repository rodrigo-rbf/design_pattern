#include <iostream>
#include <string>
#include <memory>

struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}
  
  Point(const int x, const int y) : x{x}, y{y} {}
};

struct Line
{
  Point *start, *end;
  
  Line(Point* const start, Point* const end) :
    start(start),
    end(end)
  {}

  Line(const Line &other) :
    start{new Point{*other.start}},
    end{new Point{*other.end}}
  {}

  // ~Line()
  // {
  //   delete start;
  //   delete end;
  // }

  Line deep_copy() const {
        auto result = new_main_line(start, end);
        return *result;
    }

  friend std::ostream& operator << (std::ostream& os, const Line& line) {
            os << "Line start = [" << line.start->x << ", " << line.start->y << "] and Line end = [" 
                << line.end->x << ", " << line.end->y << "]\n";
            return os;
        }

  private:

     static inline std::unique_ptr<Line> new_main_line(const Point* start, const Point* end) {
        auto line = std::make_unique<Line>(new Point(*start), new Point(*end));
        return line;
    }

};

int main(){
  Point p1(2, 1);
  Point p2(4, 3);

  Line l1{&p1, &p2};
  auto l2 = l1.deep_copy();
  std::cout << l1;
  std::cout << l2;

  l2.start->x=10;
  l2.start->y=10;
  l2.end->x = 7;
  l2.end->y = 9;

  std::cout << "------------\n";
  std::cout << l1;
  std::cout << l2;
  std::cout << l1;
    
}
