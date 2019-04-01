#include <iostream>

class Singleton
{
    private:
        //1.Make constructor private so that it cannot be accessible outside this class
        Singleton()
        {
            std::cout <<"Constructor should be called only once....!" << "\n";
        };

        //2.Make destructor private so that no one calls the destructor directly outside this class
        ~Singleton(){};
    
    public:

        //3.Provide a global access point using 'static function'.
        static Singleton& getInstance()
        {
            static Singleton singleton{}; //Single instance of this class
            return singleton;
        }

        //4.Make copy constructor as deleted
        Singleton(const Singleton&) = delete;

        //5.Make copy assignement operator as deleted
        Singleton& operator=(const Singleton&) = delete;

        void toString() const
        {
            std::cout << "Scott meyers singleton class implemenation: " << "\n";
        }

};

int main(int argc, char const *argv[])
{
    Singleton::getInstance().toString();
    Singleton::getInstance().toString();

    //Singleton st = Singleton::getInstance();

    return 0;
}
