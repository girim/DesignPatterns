#include <iostream>
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/event.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"

/* States */
class HappyState;
class SadState;
class MoreHappyState;

/* Events */
class lostMoney : public boost::statechart::event<lostMoney>
{

};
class gotMoney : public boost::statechart::event<gotMoney>
{

};



/* State Machine using CRTP*/                           /* <state machine class , InitialState> */
class PersonStateMachine : public boost::statechart::state_machine<PersonStateMachine, HappyState>
{

};

/* States using CRTP */                        /* <State class, StateMachineClass> */
class HappyState : public boost::statechart::simple_state<HappyState, PersonStateMachine>
{
    public:
        HappyState()
        {
            std::cout << "[HappyState]: constructed" << "\n";
        }

        ~HappyState(){};
        //typedef boost::statechart::custom_reaction<lostMoney> reactions;
        typedef boost::mpl::list <
            boost::statechart::custom_reaction<lostMoney>,
            boost::statechart::transition<gotMoney, MoreHappyState>
        > reactions;

        boost::statechart::result react(const lostMoney& lm)
        {
            std::cout << "I recieved the lostMoney event: " << "\n";
            return transit<SadState>();
        }

        /* boost::statechart::result react(const gotMoney& gm)
        {
            std::cout << "I recived the gotMoney event: " << "\n";
            return transit<MoreHappyState>();
        } */
};

class MoreHappyState: public boost::statechart::simple_state<MoreHappyState, PersonStateMachine>
{   
    public:
        MoreHappyState()
        {
            std::cout << "[MoreHappyState]: constructed" <<"\n";
        }

        ~MoreHappyState(){};
};

class SadState : public boost::statechart::simple_state<SadState, PersonStateMachine>
{
    public:
        SadState()
        {
            std::cout << "[SadState]: constructed" << "\n";
        }
        ~SadState(){}

        typedef boost::statechart::transition<gotMoney, HappyState> reactions;
};

int main(int argc, char const *argv[])
{
    PersonStateMachine psm{};
    psm.initiate();

    //psm.process_event(lostMoney());
    psm.process_event(gotMoney());

    return 0;
}



