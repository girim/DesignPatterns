#include <iostream>

template<typename T>
class Base
{
    public:
        void fn()
        {
            static_cast<T*>(this)->fun();
        }
};

class Derived : public Base<Derived>
{
    public:
        void fun()
        {
            std::cout << "Derived fn called: " << "\n";
        }
};

template<typename T>
void testFunc(Base<T> base)
{
    base.fn();
}

int main(int argc, char const *argv[])
{
    Derived d{};
    testFunc(d);

    d.fn();
        
    return 0;
}
