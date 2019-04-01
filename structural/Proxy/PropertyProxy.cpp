#include <iostream>

template <typename T> 
struct Property
{
    T value;

    Property(T initialValue)
    {
        *this  = initialValue;
    }

    operator T() {
        return value;
    };

    T operator=(T newValue)
    {
        value = newValue;
    }
};

class Creature
{
    public:
        Property<int> strength_{20};
        Property<int> agility_{9};
};

int main(int argc, char const *argv[])
{
    Creature creature{};
    std::cout << creature.strength_ << " " << creature.agility_ << "\n";
  
    return 0;
}
