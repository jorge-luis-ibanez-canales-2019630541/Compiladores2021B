#ifndef _POWERSETALGO_
#define _POWERSETALGO_

#include <vector>
#include <set>
#include <map>
#include <queue>

#include "Element.h"
#include "Closure.h"
#include "Kernel.h"

#include "../../Automaton/DFA.h"
#include "../../Automaton/State.h"

#include "../../Grammar/ProductionRule.h"
#include "../../Grammar/Grammar.h"

using std::vector;
using std::set;
using std::map;
using std::queue;

class PowersetAlgo{
    protected:

        Grammar G;
        DFA *DFA_F;
        int id_DFA = 1;
        vector<Symbol> all_symbs;


        map< Closure, State* > closure_to_state;
        map< State*, Closure > state_to_closure;
        map< int, State*> id_to_state;

    public:
        PowersetAlgo() {}

        PowersetAlgo(Grammar G);

        virtual set<Element*> get_move(set<Element*>, Symbol) = 0; //Abstracto
        virtual Closure get_closure(Kernel) = 0; //Abstracto

        State* map_to_state(Closure C);
        void get_powersets(Element* Start);

        map< Closure, State* > get_map_closure_to_state();
        map< State*, Closure > get_map_state_to_closure();
        map< int, State*> get_map_id_to_state();

};

#endif