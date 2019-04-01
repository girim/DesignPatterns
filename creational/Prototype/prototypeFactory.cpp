#include <iostream>
#include <memory>

class Address
{
    public:
        Address(std::string street, std::string city, std::string suite) : street_(street), city_(city), suite_(suite){}
        ~Address(){};

        Address(const Address& other) : street_(other.street_), city_(other.city_), suite_(other.suite_){}

        friend std::ostream& operator<<(std::ostream& os, const Address& addr)
        {
            os << "Address: " << " Steet: " << addr.street_ << " ,City: " << addr.city_ << " ,Suite: " << addr.suite_;
            return os; 
        }

        void setStreet(const std::string& street)
        {
            this->street_ = street;
        }

        std::string getStreet() const { return this->street_;};

        void setCity(const std::string& city)
        {
            this->city_ = city;
        }
        std::string getCity() const { return this->city_;};

        void setSuite(std::string suite)
        {
            this->suite_ = suite;
        }

        std::string getSuite() const { return this->suite_; };

    private:
        std::string street_;
        std::string city_;
        std::string  suite_;
};

class Contact
{
    public:
        Contact(std::string name, Address* address) : name_(name), address_(address){}
        ~Contact(){
            delete address_;
        }

        Contact(const Contact& other)
        {
            this->name_ = other.name_;
            address_ = new Address(*other.address_);
        }

        friend std::ostream& operator<<(std::ostream& os, const Contact& contact)
        {
            os << "Name: " << contact.name_ << " " << *contact.address_;
            return os;
        }

        void setName(std::string name)
        {
            this->name_ = name;
        }

        void setAddress(Address* address)
        {
            this->address_ = address;
        }

        Address* getAddress() const
        {
            return this->address_;
        }
    private:
        std::string name_;
        Address* address_;
};

class PrototypeFactory
{
    public:
        static std::unique_ptr<Contact> NewMainEmployee(std::string name, std::string suite)
        {
            static Contact p{"", new Address{"blr", "India", "0"}};
            return NewEmployee(name, suite, p);
        }

    private:
        static std::unique_ptr<Contact> NewEmployee(std::string name, std::string suite, const Contact& proto)
        {
            auto clone =  std::make_unique<Contact>(proto);
            clone->setName(name);
            clone->getAddress()->setSuite(suite);

            return clone;
        }
};

int main(int argc, char const *argv[])
{
    Contact John{"John", new Address{"Hebbal", "Banglore", "109"}};
    std::cout << John << "\n";

    Contact Jane = John;
    Jane.setName("Jane");
    Jane.setAddress(new Address{"Nagavara", "Blr", "109"});

    std::cout << Jane << "\n";

    auto result = PrototypeFactory::NewMainEmployee("Smith", "9300");
    std::cout << *result << "\n";

    return 0;
}
