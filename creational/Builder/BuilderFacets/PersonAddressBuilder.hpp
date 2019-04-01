#ifndef __PERSON_ADDRESS_BUILDER_HPP__
#define __PERSON_ADDRESS_BUILDER_HPP__

class PersonAddressBuilder : public PersonBuilderBase
{
    public:
        PersonAddressBuilder(Person& person) : PersonBuilderBase(person){}

        PersonAddressBuilder& at(std::string streetAddress)
        {
            person_.streetAddress_ = streetAddress;
            return *this;
        }

        PersonAddressBuilder& withPostCode(std::string postCode)
        {
            person_.postCode_ = postCode;
            return *this;
        }

        PersonAddressBuilder& in(std::string city)
        {
            person_.city_ = city;
            return *this;
        }
};

#endif