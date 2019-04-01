#include <iostream>
#include <string>
#include <sstream>

struct Shape
{
        virtual std::string str() = 0;
};

struct Circle : Shape
{
        Circle(){};
        Circle(double radius) : radius_(radius){};
        ~Circle(){};

        void setRadius(const double& radius)
        {
            this->radius_ = radius;
        }

        double getRadius() const { return this->radius_;};

        virtual std::string str() override
        {
            std::ostringstream oss;
            oss << "A circle with radius " << this->radius_;
            return oss.str();
        }

        double radius_;
};

struct Square : Shape
{
        Square() = default;
        Square(int side) : side_(side){};
        ~Square(){};

        virtual std::string str() override
        {
            std::ostringstream oss;
            oss << "A square with side " << side_ ;
            return oss.str();
        }

        void setTransperancy(unsigned int trans)
        {
            this->transperancy_ = trans;
        }

        unsigned int getTransperancy() const{ return this->transperancy_; };

        unsigned int transperancy_;
        int side_;
};

template<typename T> 
struct ColoredShape : T
{
    static_assert(std::is_base_of<Shape, T>::value, "Template arguement must be a shape");

    ColoredShape() = default;
    template<typename ...Args>
    ColoredShape(const std::string color, Args ...args) : T(std::forward<Args>(args)...), color_(color){}
                
    std::string str() override
    {
        std::ostringstream oss;
        oss << T::str() << " has color " << color_ ;
        return oss.str();
    }
    std::string color_; 
};

template <typename T>
struct TransperentShape : T
{
    static_assert(std::is_base_of<Shape, T>::value, "Template arguement must be a shape");

    TransperentShape() = default;
    template<typename ...Args>
    TransperentShape(unsigned int transperancy, Args ...args) : T(std::forward<Args>(args)...), transperancy_(transperancy){}

    std::string str() override
    {
        std::ostringstream oss;
        oss << T::str() << " has " << static_cast<float>(transperancy_)/ 255.f * 100.f << "% transperancy" << "\n";
        return oss.str();
    }

    unsigned int transperancy_;
};

int main(int argc, char const *argv[])
{
    ColoredShape<Circle> greenCircle{"Green"};
    greenCircle.radius_ = 4;

    std::cout << greenCircle.str() << "\n";

    TransperentShape<ColoredShape<Square>> blue_invisible_square{ 51 };
    blue_invisible_square.color_ = "blue";
    blue_invisible_square.side_ = 321;
  
    std::cout << blue_invisible_square.str() << std::endl;
    
    return 0;
}


