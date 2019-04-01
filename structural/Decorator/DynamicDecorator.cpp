#include <iostream>
#include <string>
#include <sstream>

struct Shape
{
    virtual std::string str() = 0; /* Pure Virtual function */
};

class Circle : public Shape
{
    public:
        Circle(double radius) : radius_(radius){};
        ~Circle(){};
    
        virtual std::string str() override
        {
            std::ostringstream oss;
            oss<< "A circle of radius " << this->radius_;
            return oss.str();
        }

        void resize(int scaleFactor)
        {
            this->radius_ *= scaleFactor;
        }

    private:
        double radius_;
};

class Square : public Shape
{
    public:
        Square(int side) : side_(side) {};
        ~Square() {};

        virtual std::string str() override
        {
            std::ostringstream oss;
            oss << "A Square with side " << this->side_;
            return oss.str();
        }
        
    private:
        int side_;
};

class ColouredCircle : public Shape
{
    public:
        ColouredCircle(Shape& shape, const std::string& color) : shape_(shape), color_(color) {};
        ~ColouredCircle(){};

        virtual std::string str() override
        {
            std::ostringstream oss;
            oss << shape_.str() << " has color " << this->color_ << "\n";
            return oss.str();
        }

    private:
        Shape& shape_;
        std::string color_;
};

class TransperentShape : public Shape
{
    public:
        TransperentShape(Shape& shape, unsigned int transperanctLevel) : shape_(shape), transperancyLevel_(transperanctLevel){};
        ~TransperentShape(){};

        virtual std::string str() override
        {
            std::ostringstream oss;
            oss << shape_.str() << " has " << static_cast<float>(transperancyLevel_) / 255.f * 100.f << " % transperancy" << "\n";
            return oss.str();
        }
    
    private:
        Shape& shape_;
        unsigned int transperancyLevel_;
};

int main(int argc, char const *argv[])
{
    Circle c1{4};
    ColouredCircle coloredCircle{c1, "Green"};

    std::cout << coloredCircle.str();

    return 0;
}
