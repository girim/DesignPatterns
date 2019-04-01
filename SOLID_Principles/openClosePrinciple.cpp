#include <iostream>
#include <vector>
#include <string>

enum class Color
{
    red, blue, green
};

enum class Size
{
    small, medium, large
};

class Product
{
    public:
        Product(std::string name, Color color, Size size) : name_(name), color_(color), size_(size){}
        ~Product(){}

        std::string getName() const { return name_;}
        Color getColor() const { return color_;}
        Size getSize() const { return size_;}

    private:
        std::string name_;
        Color color_;
        Size size_;
};

template<typename T> 
class Specification
{
    public:
        virtual bool is_satisfied(T* item) = 0; 
};

template<typename T>
class Filter
{
    public:
        virtual std::vector<T*> filter(std::vector<T*> items, Specification<T> &spec) = 0;
};

template<typename T> 
class AndSpecification : public Specification<T>
{
    public:
        AndSpecification(Specification<T>& first, Specification<T>& second) : first_(first), second_(second){}
        ~AndSpecification(){};

        bool is_satisfied(T* item)
        {
            return (first_.is_satisfied(item) && second_.is_satisfied(item));
        }

    private:
        Specification<T>& first_;
        Specification<T>& second_;
};


class ProductFilter : Filter<Product>
{
    public:
        std::vector<Product*> filter(std::vector<Product*> items, Specification<Product> &spec) override
        {
            std::vector<Product*> result;

            for(auto& item: items)
            {
                if(spec.is_satisfied(item))
                {
                    result.push_back(item);
                }
            }
            return result;
        }
};

class ColorSpecification : public Specification<Product>
{
    public:
        ColorSpecification(Color color) : color_(color){}
        ~ColorSpecification(){};

        bool is_satisfied(Product* item) override
        {
            return (item->getColor() == color_);
        }

    private:
        Color color_;
};

class SizeSpecification : public Specification<Product>
{
    public:
        SizeSpecification(Size size) : size_(size){}
        ~SizeSpecification(){}

        bool is_satisfied(Product* item) override
        {
            return (item->getSize() == size_);
        }

    private:
        Size size_;
};

int main(int argc, char const *argv[])
{
    Product Apple{"Apple", Color::red, Size::medium};
    Product Tree{"Tree", Color::green, Size::large};
    Product House{"House", Color::blue, Size::large};

    ColorSpecification spec{Color::green};
    ProductFilter pf{};
    
    std::vector<Product*> items = {&Apple, &Tree, &House};
    auto result =  pf.filter(items, spec);

    for(auto& item: result)
    {
        std::cout << item->getName() << "\n";
    }

    SizeSpecification sizeSpec{Size::large};
    result =  pf.filter(items, sizeSpec);

    for(auto& item: result)
    {
        std::cout << item->getName() << "\n";
    }

    AndSpecification<Product> aSpec{spec, sizeSpec};
    result = pf.filter(items, aSpec);

    for(auto& item: result)
    {
        std::cout << item->getName() << "\n";
    }

    return 0;
}
