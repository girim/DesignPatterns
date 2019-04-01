#ifndef __HOT_DRINKS_HPP__
#define __HOT_DRINKS_HPP__
#include <iostream>
#include <memory>

class HotDrink
{
    public:
        virtual ~HotDrink() = default;
        virtual void prepare(int volume) = 0;
};

class Tea : public HotDrink
{
    public:
        virtual void prepare(int volume) override
        {
            std::cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon" << std::endl;
        }
};

class Coffee : public HotDrink
{
    public:
        virtual void prepare(int volume) override
        {
            std::cout << "Grind some beans, boil water, pour " << volume << "ml, add cream, enjoy!" << std::endl;
        }
};

#endif //__HOT_DRINKS_HPP__