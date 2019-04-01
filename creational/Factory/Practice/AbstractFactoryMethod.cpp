#include <iostream>

enum class Options
{
    Circle,
    Square,
    Triangle
};

class Shape
{
    public:
        Shape(){};
        ~Shape(){};

    virtual void draw() = 0;
    static Shape* getShape(Options option);
};

class Circle : public Shape
{
    public:
        Circle(){};
        ~Circle(){};

    virtual void draw() override
    {
        std::cout << "Drawing Circle...." << "\n";
    }
};

class Square : public Shape
{
    public:
        Square(){};
        ~Square(){};

    virtual void draw() override
    {
        std::cout << "Drawing Square...." << "\n";
    }
};

class Triangle : public Shape
{
    public:
        Triangle(){};
        ~Triangle(){};
    
    virtual void draw() override
    {
        std::cout << "Drawing Triangle...." << "\n";
    }
};

Shape* Shape::getShape(Options option)
{
    switch (option)
    {
    case Options::Circle:
        return new Circle{};
        break;

    case Options::Square:
        return new Square{};
        break;

    case Options::Triangle:
        return new Triangle{};
        break;

    default:
        return nullptr;
        break;
    }
}


int main(int argc, char const *argv[])
{
    Circle circle{};
    Square square{};

    Shape *shape = Shape::getShape(Options::Circle);
    if(shape) shape->draw();
    delete shape;

    shape = Shape::getShape(Options::Square);
    if(shape) shape->draw();
    delete shape;

    shape = Shape::getShape(Options::Triangle);
    if(shape) shape->draw();

    delete shape;

    return 0;
}

