#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "boost/lexical_cast.hpp"

struct Database
{
    virtual std::string getPopulation(const std::string& city) = 0;
};

class SingletonDatabase : public Database
{
    public:
        //Make sure copy constructor and copy-assignement constructor are deleted
        SingletonDatabase(const SingletonDatabase& sdb) = delete;
        SingletonDatabase& operator=(const SingletonDatabase& sdb) = delete;

        static SingletonDatabase& getInstance()
        {
            static SingletonDatabase sdb{};
            return sdb;
        }

        virtual std::string getPopulation(const std::string& city) override
        {
            return capitalsDB_[city];
        }

    private:
        typedef std::string cityName;
        typedef std::string population;
        std::map<cityName, population> capitalsDB_;

        SingletonDatabase()
        {
            std::ifstream ifs("Capitals.txt");

            std::string s1, s2;
            while(getline(ifs, s1))
            {
                getline(ifs, s2);
                capitalsDB_.emplace(s1, s2);
            }
        }
       ~SingletonDatabase() {};
};

class DummyDatabase : public Database
{
    public:
        DummyDatabase()
        {
            dummyCapitals_.emplace("Alpha", "1");
            dummyCapitals_.emplace("Beta", "2");
            dummyCapitals_.emplace("Gamma", "3");
        }
        virtual std::string getPopulation(const std::string& city) override
        {
            return dummyCapitals_[city];
        }

    private:
        std::map<std::string, std::string> dummyCapitals_;
};

class SingletonRecordFinder
{
    public:
        //This class function is tightly coupled with SingeletonDb instance
        int getTotalPopulation(std::vector<std::string> cityNames)
        {
            int result{0};
        
            for(const auto& city : cityNames)
            {
                result += boost::lexical_cast<int>(SingletonDatabase::getInstance().getPopulation(city));
            }
            return result;
        }
};

class ConfigurableRecordFinder 
{
    public:
        ConfigurableRecordFinder(Database& db) : db_(db) {}

        int getTotalPopulation(std::vector<std::string> cityNames)
        {
            int result{0};
        
            for(const auto& city : cityNames)
            {
                result += boost::lexical_cast<int>(db_.getPopulation(city));
            }
            return result;
        }

        //WRONG: Cannot reassign to reference variable
        void setDBInstance(Database& db)
        {
            db_ = db;
        }

    private:
        Database& db_;
};

int main(int argc, char const *argv[])
{
    SingletonRecordFinder srf{};
    std::vector<std::string> cities{"Berlin", "Vienna"};
    std::cout << srf.getTotalPopulation(cities) << "\n";

    DummyDatabase ddb{};
    ConfigurableRecordFinder crf{ddb};

    std::vector<std::string> dCities{"Alpha", "Beta"};
    std::cout << crf.getTotalPopulation(dCities) << "\n";

    ConfigurableRecordFinder crf1{SingletonDatabase::getInstance()};
    //crf1.setDBInstance(SingletonDatabase::getInstance());
    std::cout << crf1.getTotalPopulation(cities) << "\n";

    return 0;
}
