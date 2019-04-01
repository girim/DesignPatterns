#include <iostream>
#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

int main(int argc, char const *argv[])
{
    Person p = Person::create().lives().at("Blr").withPostCode("1212").in("London")
            .works().at("IBM").as_a("Engineer").earning(30000000);

    std::cout << p << "\n";
    return 0;
}
