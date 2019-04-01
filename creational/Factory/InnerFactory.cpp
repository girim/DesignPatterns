#include <iostream>
#include <cmath>

class Point
{
    private:
        class PointFactory
        {
            public:
                static Point NewCartesianPoint(double x, double y)
                {
                    return {x, y};
                }   

                static Point NewPolarPoint(double r, double theta)
                {
                    return {r*cos(theta), r*sin(theta)};
                }
        };

        Point(double x, double y) : x_(x), y_(y){};
        double x_;
        double y_;

    public:
        ~Point(){};
        static PointFactory pointFactory_;

        friend std::ostream& operator<<(std::ostream& os, const Point& pt)
        {
            os << "{ x:" << pt.x_ << " , y:" << pt.y_ << " }";
            return os;
        }
};

int main(int argc, char const *argv[])
{
    Point pt1 = Point::pointFactory_.NewCartesianPoint(3, 4);
    Point pt2 = Point::pointFactory_.NewPolarPoint(5, 6);

    std::cout << pt1 << "\n";
    std::cout << pt2 << "\n";

    return 0;
}
