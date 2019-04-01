/* Seperation of concern
   A class should do a single primary task */
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "boost/lexical_cast.hpp"

class Journel
{
    public:
        Journel(std::string title) : title_(title) { }
        ~Journel() { }

        void addEntries(const std::string& entry)
        {
            static unsigned int count = 1;
            entries_.push_back(boost::lexical_cast<std::string>(count++) + " " + entry);
        }
        std::vector<std::string> entries_;
    private:
        std::string& title_;
};

class PersistantManager
{
    public:
        static void save(const Journel& journel, const std::string& filename)
        {
            std::ostringstream ofs(filename);

            for(auto& entry : journel.entries_)
            {
                ofs << entry;
            }   
        }
};

int main(int argc, char const *argv[])
{
    Journel j{"some"};
    j.addEntries("some jink");
    
    return 0;
}
