#ifndef __PERSON_BUILDER_HPP__
#define __PERSON_BUILDER_HPP__
#include "Person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
    public:
        ~PersonBuilderBase(){};

        operator Person() const
        {  
            return std::move(person_);
        }  

        PersonAddressBuilder lives() const;
        PersonJobBuilder works() const;

    protected:
        explicit PersonBuilderBase(Person& person) : person_(person){}
        Person& person_;
};

class PersonBuilder : public PersonBuilderBase
{
    public:
        PersonBuilder() : PersonBuilderBase(p_){};

    private:
        Person p_;
};

#endif