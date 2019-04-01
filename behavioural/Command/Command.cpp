#include <iostream>
#include <vector>

class BankAccount
{
    public:
        BankAccount(){};
        ~BankAccount(){};

        void deposite(int amount)
        {
            this->balance_ += amount;
            std::cout << "Balance after deposit: " << balance_ << "\n";
        }

        void withdraw(int amount)
        {
            if(this->balance_ - amount >=  overdraftLimit)
            {
                this->balance_ -= amount;
                std::cout << "Balance after withdraw: " << balance_ << "\n";
            }
        }

        friend std::ostream& operator<<(std::ostream& os , const BankAccount& ba)
        {
            os << "Balance : " << ba.balance_ << "\n";
            return os;
        }

    private:
        int balance_{0};
        int overdraftLimit{-500};
};

struct Command
{
    virtual void call() = 0;
};

class BankAccountCommand :  public Command
{
    public:
        BankAccount& bankAccount_;
        enum Action { deposit, withdraw} action_;
        int amount_;

        BankAccountCommand(BankAccount& ba, Action action, int amount)
            : bankAccount_(ba), action_(action), amount_(amount) {};

        ~BankAccountCommand(){};

        virtual void call() override
        {
            switch (action_)
            {
                case deposit:
                    bankAccount_.deposite(amount_);
                    break;
                
                case withdraw:
                    bankAccount_.withdraw(amount_);
                    break;

                default:
                    break;
            }
        }
};

int main(int argc, char const *argv[])
{
    BankAccount ba{};

    std::vector<BankAccountCommand> commands{
        BankAccountCommand{ba, BankAccountCommand::Action::deposit, 100},
        BankAccountCommand{ba, BankAccountCommand::Action::withdraw, 200}
    };

    for(auto& command: commands)
    {
        command.call();
    }

    std::cout << ba;

    return 0;
}
