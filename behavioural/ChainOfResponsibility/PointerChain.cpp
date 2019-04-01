#include <iostream>
#include <string>

class Creature
{
    public:
        Creature(const std::string& name, int attack, int defence)
            :   name_(name), 
                attack_(attack),
                defence_(defence){};
        
        void setName(const std::string& name) { this->name_ = name; }
        std::string getName() const { return this->name_; }

        void setAttackValue(int attack) { this->attack_ = attack; }
        int getAttackValue() const { return this->attack_; }

        void setDefenceValue(int defence) { this->defence_ = defence; }
        int getDefenceValue() const { return this->defence_; }

        friend std::ostream& operator<<(std::ostream& os , const Creature& creature)
        {
            os << " Name: " << creature.getName()
               << " AttackValue: " << creature.getAttackValue()
               << " DefenceValue: " << creature.getDefenceValue() 
               << "\n";
            return os;
        }

    private:
        std::string name_;
        int attack_;
        int defence_;
};

class CreatureModifier
{
    public:
        CreatureModifier(Creature& creature) : creature_(creature){};
        virtual ~CreatureModifier(){};

        void add(CreatureModifier* cm)
        {
            if(next) next->add(cm);
            else next = cm;                
        }

        virtual void handle() 
        {
            if(next) next->handle();
        }

    protected:
        Creature& creature_;
    private:
        CreatureModifier* next{nullptr};
};

class DoubleAttackModifier : public CreatureModifier
{
    public:
        DoubleAttackModifier(Creature& creature) : CreatureModifier(creature){}
    
        virtual void handle() override
        {
            creature_.setAttackValue(creature_.getAttackValue() * 2);
            CreatureModifier::handle();
        }
};

class IncreaseDefenceValue : public CreatureModifier
{
    public:
        IncreaseDefenceValue(Creature& creature) : CreatureModifier(creature){};

        virtual void handle() override
        {
            if(creature_.getAttackValue() <= 2)
            {
                creature_.setDefenceValue(creature_.getDefenceValue() + 1 );
            }
            CreatureModifier::handle();
        }
};

class NoBonusModifier : public CreatureModifier
{
    public:
        NoBonusModifier(Creature& creature) : CreatureModifier(creature){};

        virtual void handle() override
        {
            //do nothing;
        }
};

int main(int argc, char const *argv[])
{
    Creature goblin{"Goblin", 1, 1};
    CreatureModifier root{goblin};

    DoubleAttackModifier dam1{goblin};
    DoubleAttackModifier dam2{goblin};
    IncreaseDefenceValue idv{goblin};
    NoBonusModifier nbm{goblin};

    root.add(&dam1);
    root.add(&idv);
    root.add(&nbm);
    root.add(&dam2);

    root.handle();
    std::cout << goblin;

    return 0;
}
