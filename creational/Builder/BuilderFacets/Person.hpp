#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>
#include <string>

class PersonBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;

class Person
{
    public:
        ~Person(){};

        friend PersonBuilder;
        friend PersonAddressBuilder;
        friend PersonJobBuilder;

        static PersonBuilder create();

        friend std::ostream& operator<<(std::ostream& os, const Person& obj)
        {
            return os
                << "street_address: " << obj.streetAddress_
                << " post_code: " << obj.postCode_
                << " city: " << obj.city_
                << " company_name: " << obj.companyName_
                << " position: " << obj.position_
                << " annual_income: " << obj.annualIncome_;
        }

        Person(Person&& other)
            : streetAddress_{move(other.streetAddress_)},
              postCode_{move(other.postCode_)},
              city_{move(other.city_)},
              companyName_{move(other.companyName_)},
              position_{move(other.position_)},
              annualIncome_{other.annualIncome_}
        {}

        Person& operator=(Person&& other)
        {
            if (this == &other)
              return *this;
            streetAddress_ = move(other.streetAddress_);
            postCode_ = move(other.postCode_);
            city_ = move(other.city_);
            companyName_ = move(other.companyName_);
            position_ = move(other.position_);
            annualIncome_ = other.annualIncome_;

            return *this;
        }     

    private:
        Person(){};

        std::string streetAddress_;
        std::string postCode_;
        std::string city_;

        std::string companyName_;
        std::string position_;
        int annualIncome_{0};
};

#endif //__PERSON_HPP__