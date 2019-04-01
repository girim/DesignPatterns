#include "HotDrinkFactory.hpp"
#include "TeaFactory.hpp"
#include "CoffeeFactory.hpp"
#include <map>
#include <string>

class DrinkFactory
{
    public:
        DrinkFactory()
        {
            factories_["Tea"] = std::make_unique<TeaFactory>();
            factories_["Coffee"] =  std::make_unique<CoffeeFactory>();
        }

        std::unique_ptr<HotDrink> makeDrinks(const std::string& drinks)
        {
            auto drink = factories_[drinks]->make();
            drink->prepare(200);
            return drink;
        }

    private:
        std::map<std::string, std::unique_ptr<HotDrinkFactory>> factories_;
};

