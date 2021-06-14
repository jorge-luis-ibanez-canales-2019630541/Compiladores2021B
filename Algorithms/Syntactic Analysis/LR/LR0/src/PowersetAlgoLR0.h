#ifndef _POWERSETALGOLR0_
#define _POWERSETALGOLR0_

#include <set>
#include <map>
#include <utility>

#include "../../LR/Element.h"
#include "../../LR/Closure.h"
#include "../../LR/Kernel.h"
#include "../../LR/PowersetAlgo.h"

#include "ElementLR0.h"

#include "../../../Automaton/DFA.h"
#include "../../../Automaton/State.h"

#include "../../../Grammar/ProductionRule.h"
#include "../../../Grammar/Grammar.h"
#include "../../../Grammar/Symbol.h"

using std::vector;
using std::set;
using std::map;
using std::pair;

class PowersetAlgoLR0: public PowersetAlgo{
    private:
        map< pair<ProductionRule, int>, ElementLR0*> parts_to_element;

    public:

        PowersetAlgoLR0() {}
        PowersetAlgoLR0(Grammar G): PowersetAlgo(G) {}

    
        ElementLR0* map_new_element(ProductionRule PR, int idx_point = 0);

        set<Element*> get_move(set<Element*> elements, Symbol S);

        Closure get_closure(Kernel K);
};

#endif