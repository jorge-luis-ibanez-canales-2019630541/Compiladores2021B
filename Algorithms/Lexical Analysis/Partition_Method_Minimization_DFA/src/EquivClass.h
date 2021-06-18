#ifndef _EQUIVCLASS_
#define _EQUIVCLASS_

#include<set>
#include "../../Automaton/State.h"

using std::set;

class EquivClass: public set<State*>{
    private:    

    public:
        EquivClass() {}
        EquivClass(set<State*> states) { this->insert(states.begin(), states.end()); }

        bool is_inside(State* S);

};

#endif