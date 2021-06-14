#ifndef _POWERSETALGOLR1_
#define _POWERSETALGOLR1_

#include <set>
#include <map>
#include <utility>

#include "../../LR/Element.h"
#include "../../LR/Closure.h"
#include "../../LR/Kernel.h"
#include "../../LR/PowersetAlgo.h"

#include "ElementLR1.h"

#include "../../../Automaton/DFA.h"
#include "../../../Automaton/State.h"

#include "../../../Grammar/ProductionRule.h"
#include "../../../Grammar/Grammar.h"
#include "../../../Grammar/Symbol.h"
#include "../../../Grammar/First.h"
#include "../../../Grammar/FirstFactory.h"

using std::vector;
using std::set;
using std::map;
using std::tuple;

class PowersetAlgoLR1: public PowersetAlgo{
    private:
        map< tuple<ProductionRule, Terminal, int>, ElementLR1*> parts_to_element;
        FirstFactory FirstFact;
        vector<Symbol> get_symbols_slice(ProductionRule PR, int idx_left, int idx_right = -1);
        set<Element*> get_move(set<Element*> elements, Symbol S);
        Closure get_closure(Kernel K);

    public:

        PowersetAlgoLR1() {}
        PowersetAlgoLR1(Grammar G): PowersetAlgo(G) { FirstFact = FirstFactory(G); }
        
        ElementLR1* map_new_element(ProductionRule PR, Terminal T, int idx_point = 0);
};

#endif