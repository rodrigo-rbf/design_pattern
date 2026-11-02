#include "factory/point_type.hpp"


int main()
{

    Point c = Point::Factory.newCartesian(4, 3);
    std::cout << c << '\n';

    Point p = Point::Factory.newPolar(5, 0.6);
    std::cout << p << '\n';

    return 0;
}