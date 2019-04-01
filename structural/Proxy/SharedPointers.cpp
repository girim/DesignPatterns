#include <iostream>
#include <memory>


struct BankAccount
{
    virtual ~BankAccount() = default;
    virtual void deposite(int amount) = 0;
    virtual void withdraw(int amount) = 0;
};

class CurrentAccount : public BankAccount
{
    public:
        CurrentAccount(int balance) : balance_(balance){};
        ~CurrentAccount(){};
    
        virtual void deposite(int amount) override
        {
            this->balance_ += amount;
        }

        virtual void withdraw(int amount) override
        {
            if(amount < this->balance_) this->balance_ -= amount;
        }

        friend std::ostream& operator<<(std::ostream& os, const CurrentAccount& ca)
        {
            os << "Current balance: " << ca.balance_ << "\n";
            return os;
        }

    private:
        int balance_;
};

int main(int argc, char const *argv[])
{
    BankAccount* a = new CurrentAccount(1000);
    a->deposite(200);

    auto p = std::make_shared<CurrentAccount>(900);
    p->deposite(800);

    std::cout << *p;

    return 0;
}


