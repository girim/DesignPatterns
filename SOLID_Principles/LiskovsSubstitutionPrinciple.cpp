#include <iostream>

class Rectangle
{
    public:
        Rectangle(double width, double height);
        ~Rectangle();

        double getWidth() const { return width_;}
        // void setWidth(double width);

        double getHeight() const { return height_;}
        // void setHeight(double height);

        virtual void setWidth(double width)
        {
            this->width_ = width;
        }

        virtual void setHeight(double height)
        {
            this->height_ = height;
        }

        double getArea() const { return width_ * height_;}

    protected:
        double width_, height_;
};

Rectangle::Rectangle(double width, double height) : width_(width), height_(height)
{
}

Rectangle::~Rectangle()
{
}

void process(Rectangle& rect)
{
    double width = rect.getWidth();
    rect.setHeight(10);

    std::cout << "Rectangle has " << (width * rect.getHeight()) << " and area: " << rect.getArea() << "\n";
}

class Square : public Rectangle
{
    public:
        Square(double sz) : Rectangle(sz, sz){};
        ~Square(){};
        
        void setWidth(double width) override
        {
            this->width_ = this->height_ = width;
        }

        void setHeight(double height) override
        {
            this->width_ = this->height_ = height;
        }
};

int main(int argc, char const *argv[])
{
    Rectangle rect{4, 5};
    process(rect);

    Square sq{6};
    process(sq);

    return 0;
}
