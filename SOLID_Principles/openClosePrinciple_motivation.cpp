#include <iostream>
#include <vector>
#include <string>

enum class Color
{
    red, 
    blue,
    green
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

        Color getColor() const { return color_;}
        Size getSize() const { return size_;}
        std::string getName() const { return name_;}

    private:
        std::string name_;
        Color color_;
        Size size_; 
};

class ProductFilter
{
    public:
        ProductFilter(){};
        ~ProductFilter(){};

        std::vector<Product*> filterByColor(std::vector<Product*> items, Color color)
        {
            std::vector<Product*> result;

            for(auto& item : items)
            {
                if (item->getColor() == color)
                {
                    result.push_back(item);
                }
            }
            return result;
        }

        std::vector<Product*> filterBySize(std::vector<Product*> items, Size size)
        {
            std::vector<Product*> result;
            
            for(auto& item : items)
            {
                if(item->getSize() ==  size)
                {
                    result.push_back(item);
                }
            }
            return result;
        }

        std::vector<Product*> filterByColorAndSize(std::vector<Product*> items, Color color, Size size)
        {
            std::vector<Product*> result;

            for(auto&& item : items)
            {
                if(item->getColor() == color && item->getSize() == size)
                {
                    result.push_back(item);
                }
            }
            return result;
        }
};

int main(int argc, char const *argv[])
{
    Product apple{"apple", Color::green, Size::small};
    Product tree{"tree", Color::green, Size::large};
    Product house("house", Color::blue, Size::large);

    std::vector<Product*> items{&apple, &tree, &house};

    ProductFilter productFilter{};
    auto result = productFilter.filterByColor(items, Color::green);

    for(auto& item : result)
    {
        std::cout << item->getName() << "\n";
    }

    result = productFilter.filterBySize(items, Size::large);

    for(auto& item : result)
    {
        std::cout << item->getName() << "\n";
    }

    result = productFilter.filterByColorAndSize(items, Color::green, Size::large);
    
    for(auto& item : result)
    {
        std::cout << item->getName() << "\n";
    }

    return 0;
}
