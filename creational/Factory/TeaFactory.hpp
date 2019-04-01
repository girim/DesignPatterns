#ifndef __TEA_FACTORY_HPP__
#define __TEA_FACTORY_HPP__

#include "HotDrinkFactory.hpp"

class TeaFactory : public HotDrinkFactory
{
    public:
        virtual std::unique_ptr<HotDrink> make() const override
        {
            return std::make_unique<Tea>();
        }
};

#endif