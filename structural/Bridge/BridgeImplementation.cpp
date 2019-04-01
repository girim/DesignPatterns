#include <iostream>

struct Renderer
{
    virtual void renderCircle(double x, double y, double radius) = 0;
};

class RasterRenderer : public Renderer
{
    public:
        virtual void renderCircle(double x, double y, double radius) override
        {
            std::cout << "Rasterizing the circle of radius: " << radius << "\n";
        }
};

class VectorRenderer : public Renderer
{
    public:
        virtual void renderCircle(double x, double y, double radius) override
        {
            std::cout << "Vectorizing the circle of radius: " << radius << "\n";
        }
};

struct Shape
{
    protected:
        Shape(Renderer& renderer) : renderer_(renderer){}; // this is the bridge
        Renderer& renderer_;
    public:
        virtual void draw() = 0;
        virtual void resize(double radius) = 0;
};

class Circle : public Shape
{
    public:
        Circle(Renderer& renderer,  double x, double y, double radius) : Shape(renderer), x_(x), y_(y), radius_(radius){};
        ~Circle(){};

        virtual void draw() override
        {
            renderer_.renderCircle(x_, y_, radius_);
        }

        virtual void resize(double radius) override
        {
            this->radius_ += radius;
        }

    private:
        double x_;
        double y_;
        double radius_;
};

int main(int argc, char const *argv[])
{
    RasterRenderer rasterRenderer{};
    Circle circle{rasterRenderer, 5, 5, 10};

    circle.draw();
    circle.resize(2);
    circle.draw();

    return 0;
}


