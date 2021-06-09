#ifndef _POWERSETCONSTRUCTION_
#define _POWERSETCONSTRUCTION_


#include<set>
#include<map>
#include<vector>
#include "../../Automaton/State.h"
#include "../../Automaton/NFA.h"
#include "../../Automaton/DFA.h"
#include "Closure.h"
#include "Powerset.h"

using std::vector;
using std::set;
using std::map;

class PowersetConstruction{
    private:

        NFA* _NFA1;
        int id_DFA = 1;
        map< Closure, State* > closure_to_state; //Non deterministic set of states TO state of DFA
        map< State*, Closure > state_to_closure; //state of DFA TO Non deterministic set of states

        set<State*> get_move(const set<State*> &T, char label);

        bool is_void_state(State *S);
        bool is_final_state(State *S);

        State* map_closure(const Closure &closure);

    public:
        PowersetConstruction(NFA* NFA1): _NFA1(NFA1) {}        
        DFA* run();

};

#endif