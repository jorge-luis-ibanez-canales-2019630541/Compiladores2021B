#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>

#include "../../LR/Element.h"
#include "../../LR/Closure.h"
#include "../../LR/Kernel.h"
#include "../../LR/PowersetAlgo.h"


#include "ElementLR0.h"
#include "PowersetAlgoLR0.h"

#include "../../../Automaton/DFA.h"
#include "../../../Automaton/State.h"

#include "../../../Grammar/ProductionRule.h"
#include "../../../Grammar/Grammar.h"
#include "../../../Grammar/Symbol.h"

using std::vector;
using std::set;
using std::map;
using std::queue;
using std::pair;


ElementLR0* PowersetAlgoLR0::map_new_element(ProductionRule PR, int idx_point)
{
    if(!parts_to_element.count({PR, idx_point}))
    {
        ElementLR0 *new_element = new ElementLR0(PR, idx_point);
        parts_to_element[{PR, idx_point}] = new_element;
    }
    return parts_to_element[{PR, idx_point}];
}


set<Element*> PowersetAlgoLR0::get_move(set<Element*> elements, Symbol S)
{
    set<Element*> element_reachables;

    for(Element *E: elements)
    {
        ElementLR0 *ELR0 = (ElementLR0*) E;
        ProductionRule PR = ELR0->get_production();

        if(ELR0->get_idx_point()+1 < PR.get_sz() && PR.get_symbol_right( ELR0->get_idx_point()+1) == S)
        {
            ProductionRule PR = ELR0->get_production();
            int idx_point = ELR0->get_idx_point();
            PR.erase_symbol_by_idx(idx_point);

            ElementLR0 *new_element = map_new_element(PR, idx_point+1);
            element_reachables.insert(new_element);
        }
    }

    return element_reachables;
}

Closure PowersetAlgoLR0::get_closure(Kernel K)
{
    Closure Closure_p(K);

    queue< Element* > q_bfs;
    for(Element* E: K)
        q_bfs.push(E);

    set< ElementLR0* > elem_processed;
    while(!q_bfs.empty())
    {
        
        ElementLR0* curr = (ElementLR0*) q_bfs.front(); q_bfs.pop();
        ProductionRule PR = curr->get_production();
        

        if(curr->get_idx_point()+1  < PR.get_sz() )
        {

            Symbol S = PR.get_symbol_right( curr->get_idx_point() + 1 );
            
            if( !S.is_terminal() )
            {
                vector<int> productions_of_s = G.get_idx_productions_of_nt(S);

                for(int idx_production: productions_of_s )
                {
                    ProductionRule PR = G.get_production_rule(idx_production);

                
                    ElementLR0 *new_element = map_new_element(PR);
                    if(elem_processed.count(new_element)) continue;
                    
                    elem_processed.insert(new_element);
                    Closure_p.insert(new_element);
                    q_bfs.push(new_element);
                }
            }
        }
    }   
    return Closure_p;
}
