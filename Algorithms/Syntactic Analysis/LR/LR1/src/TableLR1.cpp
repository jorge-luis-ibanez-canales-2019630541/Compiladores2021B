#include <map>
#include <utility>

#include "../../LR/Element.h"
#include "../../LR/Closure.h"


#include "ElementLR1.h"
#include "PowersetAlgoLR1.h"
#include "TableLR1.h"


#include "../../../Automaton/State.h"


#include "../../../Grammar/ProductionRule.h"
#include "../../../Grammar/FollowFactory.h"
#include "../../../Grammar/Follow.h"
#include "../../../Grammar/Grammar.h"
#include "../../../Grammar/Symbol.h"


using std::map;
using std::pair;


TableLR1::TableLR1(Grammar G): TableLR(G)
{
    PALR1 = PowersetAlgoLR1(G);
    FollowFact = FollowFactory(G);

    extension = ProductionRule( NonTerminal("Q"), {G.get_start()} );
    PALR1.get_powersets(new ElementLR1(extension, Terminal("$")));
    state_to_closure = PALR1.get_map_state_to_closure();
    id_to_state = PALR1.get_map_id_to_state();

    get_table();
}

void TableLR1::get_action_accept()
{
    ElementLR1 *E_ACC = PALR1.map_new_element( extension, Terminal("$")  , 1);

    for(pair<State*, Closure> SC: state_to_closure)
    {
        State* S = SC.first;
        Closure C = SC.second;
        if(C.is_inside(E_ACC))
        {
            action[{S->get_id(), Terminal("$")}] = {'A',1};
        }
    }
}


void TableLR1::get_action_reduce()
{
    for(pair<State*, Closure> SC: state_to_closure)
    {
        State* S = SC.first;
        Closure C = SC.second;

        for(Element *E: C)
        {
            ElementLR1 *ELR1 = (ElementLR1*) E;
            ProductionRule PRE = ELR1->get_production();
            Terminal lookahead = ELR1->get_lookahead();

            if( ELR1->get_idx_point()+1 == PRE.get_sz() &&  PRE.get_left_part() != extension.get_left_part() ) //punto al final
            {
                ProductionRule PR_no_point = PRE;
                PR_no_point.erase_symbol_by_idx(ELR1->get_idx_point());

                int idx_production = G.get_idx_of_production(PR_no_point);

                action[{S->get_id(), lookahead}] = {'r', idx_production};
            }
        }
    }
}
