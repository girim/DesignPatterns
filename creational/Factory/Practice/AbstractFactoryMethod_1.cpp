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


class ShapeFactory
{
    public:
        ShapeFactory(){};
        ~ShapeFactory(){};

    virtual Shape* createShape() = 0;

    virtual void draw()
    {
        Shape *shape = createShape();
        shape->draw();
    }
};

class CircleFactory : public ShapeFactory
{
    public:
        CircleFactory(){};
        ~CircleFactory(){};

    virtual Shape* createShape() override
    {
        return new Circle{};
    }
};

class SquareFactory : public ShapeFactory
{
    public:
        SquareFactory(){};
        ~SquareFactory(){};
    
    virtual Shape* createShape() override
    {
        return new Square{};
    }
};

class TriangleFactory : public ShapeFactory
{
    public:
        TriangleFactory(){};
        ~TriangleFactory(){};

    virtual Shape* createShape() override
    {
        return new Triangle{};
    }

};

class Application
{
    public:
        Application(){};
        ~Application(){};
    
    static ShapeFactory* createDesiredShape(Options option)
    {
        ShapeFactory *shapeFactory;
        switch (option)
        {
        case Options::Circle:
            shapeFactory = new CircleFactory{};
            break;
        
        case Options::Square:
            shapeFactory = new SquareFactory{};
            break;
        
        case Options::Triangle:
            shapeFactory = new TriangleFactory{};
            break;
        
        default:
            shapeFactory =  nullptr;
            break;
        }

        return shapeFactory;
    }
};

int main(int argc, char const *argv[])
{
    ShapeFactory *shapeFactory = Application::createDesiredShape(Options::Square);
    shapeFactory->draw();

    shapeFactory = Application::createDesiredShape(Options::Circle);
    shapeFactory->draw();

    shapeFactory = Application::createDesiredShape(Options::Triangle);
    shapeFactory->draw();

    return 0;
}
