#ifndef __COFFEE_FACTORY__
#define __COFFEE_FACTORY__
#include "HotDrinkFactory.hpp"

class CoffeeFactory : public HotDrinkFactory
{
    public:
        virtual std::unique_ptr<HotDrink> make() const override
        {
            return std::make_unique<Coffee>();
        }
};

#endif