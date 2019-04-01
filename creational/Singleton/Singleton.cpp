#include <iostream>
#include <fstream>
#include <map>
#include <string>

class SingletonDatabase
{
    public:
        ~SingletonDatabase(){}

        SingletonDatabase(const SingletonDatabase& sdb) = delete;
        SingletonDatabase& operator=(const SingletonDatabase& sdb) = delete;

        static SingletonDatabase & getSingletonDatabaseInstance()
        {
            static SingletonDatabase sdb{};   //create an static instance and return a ref to it.
            return sdb;
        }

        std::string getPopulationOf(const std::string& city)
        {
            return capitals_[city];
        }

    private:
        std::map<std::string, std::string> capitals_;

        //Make the constructor private
        SingletonDatabase()
        {
            std::ifstream ifs("Capitals.txt");

            std::string s1, s2;
            while(getline(ifs, s1))
            {
                getline(ifs, s2);
                capitals_[s1] =  s2;
            }
        }
};

int main(int argc, char const *argv[])
{
    auto result = SingletonDatabase::getSingletonDatabaseInstance().getPopulationOf("Berlin");
    std::cout << result << "\n";

    return 0;
}
