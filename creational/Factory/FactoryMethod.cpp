#include <iostream>
#include <cmath>

class Point
{
    public:
        ~Point() = default;

        static Point NewCartesionPoint(double x, double y)
        {
            return {x, y};
        }

        static Point NewPolarPoint(double r, double theta)
        {
            return {r*cos(theta), r*sin(theta)};
        }

        friend std::ostream& operator<<(std::ostream& os , const Point& pt)
        {
            os << "{ x: " << pt.x_ << ", " << pt.y_ << " }";
            return os;
        }

    private:
        //constructor is Private
        Point(double x, double y) : x_(x), y_(y){};
        double x_;
        double y_;
};

int main(int argc, char const *argv[])
{
    Point pt1 = Point::NewCartesionPoint(5, 6);
    Point pt2 = Point::NewPolarPoint(5, 7);

    std::cout << pt1 << std::endl;
    std::cout << pt2 << std::endl;

    return 0;
}

