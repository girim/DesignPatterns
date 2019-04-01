#include <iostream>

class Address
{
    public:
        Address(std::string street, std::string city, std::string suite) : street_(street), city_(city), suite_(suite){}
        ~Address(){};

        friend std::ostream& operator<<(std::ostream& os, const Address& addr)
        {
            os << "Address: " << " Steet: " << addr.street_ << " ,City: " << addr.city_ << " ,Suite: " << addr.suite_;
            return os; 
        }

    private:
        std::string street_;
        std::string city_;
        std::string  suite_;
};

class Contact
{
    public:
        Contact(std::string name, Address address) : name_(name), address_(address){}
        ~Contact(){}

        friend std::ostream& operator<<(std::ostream& os, const Contact& contact)
        {
            os << "Name: " << contact.name_ << " " << contact.address_;
            return os;
        }

        void setName(std::string name)
        {
            this->name_ = name;
        }

        void setAddress(Address address)
        {
            this->address_ = address;
        }

    private:
        std::string name_;
        Address address_;
};

int main(int argc, char const *argv[])
{
    Contact John{"John", {"Hebbal", "Banglore", "109"}};
    std::cout << John << "\n";

    Contact Jane = John;
    Jane.setName("Jane");
    Jane.setAddress({"Nagavara", "Blr", "109"});

    std::cout <<Jane << "\n";

    return 0;
}
