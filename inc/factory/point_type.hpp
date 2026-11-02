#ifndef _FACTORY_POINT_TYPE_HPP_
#define _FACTORY_POINT_TYPE_HPP_

#include <cmath>
#include <iostream>
#include <sstream>
#include <ostream>

enum class PointType
{
    cartesian,
    polar
};

class Point
{
    private:
        Point(double x, double y) : x(x), y(y){}
        double x, y;
    public:
        friend std::ostream& operator << (std::ostream& os, const Point& point) {
            os << "x: " << point.x << " y: " << point.y;
            return os;
        }
    private:
        class PointFactory
        {
            PointFactory(){}
            public:
                static Point newCartesian(double x, double y)
                {
                    return {x, y};
                }

                static Point newPolar(double r, double theta)
                {
                    return {r*cos(theta), r*sin(theta)};
                }
        };
    public:
        static PointFactory Factory;
};


#endif