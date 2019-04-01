#include <iostream>
#include "boost/statechart/state_machine.hpp"
#include "boost/statechart/simple_state.hpp"
#include "boost/statechart/event.hpp"
#include "boost/statechart/transition.hpp"
#include "boost/statechart/custom_reaction.hpp"

/* States */
class HappyState;
class SadState;

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

        /* Event handler */
        typedef boost::statechart::transition<lostMoney, SadState> reactions;
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

    psm.process_event(lostMoney());
    psm.process_event(gotMoney());

    return 0;
}



