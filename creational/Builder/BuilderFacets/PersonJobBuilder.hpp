#ifndef __PERSON_JOB_BUILDER_HPP__
#define __PERSON_JOB_BUILDER_HPP__

class PersonJobBuilder : public PersonBuilderBase
{
public:
    PersonJobBuilder(Person& person) : PersonBuilderBase(person){};
    ~PersonJobBuilder(){};

    PersonJobBuilder& at(std::string company)
    {
        person_.companyName_ =  company;
        return *this;
    }

    PersonJobBuilder& as_a(std::string position)
    {
        person_.position_ = position;
        return *this;
    }

    PersonJobBuilder& earning(int salary)
    {
        person_.annualIncome_ =  salary;
        return *this;
    }
};

#endif