#include <iostream>
#include <cmath>

class Point
{
    public:
        Point(double x, double y) : x_(x), y_(y){}
        ~Point(){};

        friend std::ostream& operator<<(std::ostream& os, const Point& pt)
        {
            os << "{ x: " << pt.x_ << " , y:" << pt.y_ << "}";
            return os; 
        }

    private:
        double x_;
        double y_;
};

//Factory class
class PointFactory
{
    public:
        PointFactory(){};
        ~PointFactory(){};

        static Point NewCartesianPoint(double x, double y)
        {
            return {x, y};
        }

        static Point NewPolarPoint(double r, double theta)
        {
            return {r*cos(theta), r*sin(theta)};
        }
};

int main(int argc, char const *argv[])
{
    Point p = PointFactory::NewCartesianPoint(3, 4);
    Point p1 =  PointFactory::NewPolarPoint(5, 6);

    std::cout << p << "\n";
    std::cout << p1 << "\n";

    return 0;
}
