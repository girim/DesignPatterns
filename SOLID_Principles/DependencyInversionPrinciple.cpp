#include <iostream>
#include <vector>
#include <string>
#include <tuple>

/* 1. High-Level modules should not depend on Low-Level modules, Instead both should depend on 'Abstractions'
   2. Abstractions should not depend on details, Details should depend on Abstractions */

enum class Relationship
{
    Parent,
    Child,
    Sibling
};

class Person
{
    public:
        Person(std::string name) : name_(name){};
        ~Person(){};

        std::string name_;
};

class RelationshipBrowser                       // Abstraction
{
    public:
        virtual std::vector<Person> findAllChildrenOf(const std::string& person) = 0;
};

class Relationships : public RelationshipBrowser  //low-level
{
    private:
        std::vector<std::tuple<Person, Relationship, Person>> relations_;

    public:
        void addParentAndChild(const Person& parent, const Person& child)
        {
            relations_.push_back({parent, Relationship::Parent, child});
            relations_.push_back({child, Relationship::Child, parent});
        }

        std::vector<Person> findAllChildrenOf(const std::string& person)
        {
            std::vector<Person> result;

            for(auto& [first, rel, second] : relations_)
            {
                if(first.name_ == person && rel == Relationship::Parent)
                {
                    result.push_back(second);
                }
            }

            return result;
        }
};

class Research       //high-level
{
    public:
        Research(){};
        ~Research(){};

        void doResearch(RelationshipBrowser& browser)
        {
            for(auto&& person : browser.findAllChildrenOf("John"))
            {
                std::cout << "John has a child called: " << person.name_ << "\n";
            }
        }
    /* void doResearch(const Relationships& relationships)
    {
        for(auto& [first, relation, second] : relationships.relations_)
        {
            if(first.name_ == "John" && relation == Relationship::Parent)
            {
                std::cout << "John has a child called: " << second.name_ << "\n";
            }
        }
    } */
};

int main(int argc, char const *argv[])
{
    Person John{"John"};
    Person Chris{"Chris"};
    Person Matt{"Matt"};

    Relationships relationships{};
    relationships.addParentAndChild(John, Chris);
    relationships.addParentAndChild(John, Matt);

    Research _;
    _.doResearch(relationships);

    return 0;
}


