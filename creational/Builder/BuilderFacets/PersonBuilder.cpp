#include "PersonBuilder.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonJobBuilder.hpp"

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder{person_};
}

PersonJobBuilder PersonBuilderBase::works() const
{
    return PersonJobBuilder{person_};
}