#ifndef __PERSON_HPP__
#define __PERSON_HPP__
#include <string>
#include <iostream>

class Person
{
    public:
        std::string name_;
        Person(const std::string& name);
        ~Person();

        class PersonImpl;
        PersonImpl* impl_; /* Bridge to Person implemention */

        void greet();
};

#endif