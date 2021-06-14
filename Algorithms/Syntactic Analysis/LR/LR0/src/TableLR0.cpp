#include <map>
#include <utility>

#include "../../LR/Element.h"
#include "../../LR/Closure.h"


#include "ElementLR0.h"
#include "PowersetAlgoLR0.h"
#include "TableLR0.h"


#include "../../../Automaton/State.h"


#include "../../../Grammar/ProductionRule.h"
#include "../../../Grammar/FollowFactory.h"
#include "../../../Grammar/Follow.h"
#include "../../../Grammar/Grammar.h"
#include "../../../Grammar/Symbol.h"


using std::map;
using std::pair;


TableLR0::TableLR0(Grammar G): TableLR(G) { 

    PALR0 = PowersetAlgoLR0(G);
    FollowFact = FollowFactory(G);

    ProductionRule extension = ProductionRule( NonTerminal("S"), {G.get_start()} ); //!S -> inicio
    PALR0.get_powersets(new ElementLR0(extension));
    state_to_closure = PALR0.get_map_state_to_closure();
    id_to_state = PALR0.get_map_id_to_state();

    

    get_table();
}

void TableLR0::get_action_accept()
{
    ProductionRule extension( NonTerminal("S"), {G.get_start()} );
    ElementLR0 *E_ACC = PALR0.map_new_element( extension, 1  );


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

void TableLR0::get_action_reduce()
{
    for(pair<State*, Closure> SC: state_to_closure)
    {
        State* S = SC.first;
        Closure C = SC.second;


        for(int i = 0; i<G.get_sz(); i++)
        {
            ProductionRule PR = G.get_production_rule(i);
            ElementLR0 *pr_with_pointer_end = PALR0.map_new_element(PR, PR.get_sz()); //! AGUAS

            if(C.is_inside(pr_with_pointer_end))
            {
                Follow FA = FollowFact.get_follow(PR.get_left_part());

                for(Terminal T: FA)
                {
                    action[{S->get_id(), T}] = {'r', i};
                }
            }
        }
    }
}

