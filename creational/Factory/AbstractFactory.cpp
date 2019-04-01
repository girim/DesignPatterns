#include "DrinkFactory.hpp"

int main(int argc, char const *argv[])
{
    DrinkFactory df{};
    df.makeDrinks("Tea");
    df.makeDrinks("Coffee");
    
    return 0;
}
