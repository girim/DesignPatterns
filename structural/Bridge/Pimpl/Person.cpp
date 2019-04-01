#include "Person.hpp"

class Person::PersonImpl
{
    public:
        void greet(Person* p);
};

void Person::PersonImpl::greet(Person* p)
{
    std::cout << "Person name is: " << p->name_ << "\n";
}

/* Person */
Person::Person(const std::string& name) : name_(name), impl_(new PersonImpl){};
Person::~Person(){}

void Person::greet()
{
    impl_->greet(this);
}



