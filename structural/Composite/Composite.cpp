#include <iostream>
#include <vector>

struct GroupObjects
{
    virtual void draw() = 0;
};

class Circle : public GroupObjects
{
    public:
        virtual void draw() override
        {
            std::cout << "Drawing circle ...." << "\n";
        }
};

class Group : public GroupObjects
{
    public:
        Group(const std::string& name) : name_(name){};
        ~Group(){};

        virtual void draw() override
        {
            std::cout << "Drawing group " << name_ <<"\n";
            for(auto& obj : objects_)
            {
                obj->draw();
            }
        }

        void addObjects(GroupObjects* obj)
        {
            objects_.push_back(obj);
        }

    private:
        std::string name_;
        std::vector<GroupObjects*> objects_;
};

int main(int argc, char const *argv[])
{
    Circle c1{}, c2{};
    Group grp{"Circles"};
    grp.addObjects(&c1);
    grp.addObjects(&c2);

    grp.draw();

    Group subgrp{"OtherCircles"};
    subgrp.addObjects(&c1);
    subgrp.addObjects(&c2);
    subgrp.addObjects(&grp);

    subgrp.draw();

    return 0;
}
