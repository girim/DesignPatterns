#ifndef __HOT_DRINK_FACTORY_HPP__
#define __HOT_DRINK_FACTORY_HPP__
#include "HotDrinks.hpp"

class HotDrinkFactory
{
    public:
        virtual std::unique_ptr<HotDrink> make() const = 0;
};

#endif //__HOT_DRINK_FACTORY_HPP__