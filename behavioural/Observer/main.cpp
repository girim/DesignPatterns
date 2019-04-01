#include <iostream>
#include "Observable.hpp"
#include "Observer.hpp"

class Person : public Observable<Person>
{
    public:
        Person(int age) : age_(age){}
        ~Person(){};

        void setAge(int age)
        {
            if(this->age_ == age) return;

            this->age_ = age;
            notify(*this, "age");
        }

        int getAge() const { return this->age_; };

    private:
        int age_;
};

class ConsolePersonObserver : public Observer<Person>
{
    public:
        virtual void field_changed(Person& source, const std::string& fieldName) override
        {
            std::cout << "Person's " << fieldName << " changed to : " << source.getAge() << "\n";
        }
};

int main(int argc, char const *argv[])
{
    Person p1{10};

    ConsolePersonObserver cpo{};
    p1.subscribe(cpo);

    p1.setAge(20);

    return 0;
}
