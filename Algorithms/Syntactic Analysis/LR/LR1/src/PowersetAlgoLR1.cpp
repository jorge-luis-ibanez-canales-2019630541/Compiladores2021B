#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>

#include "../../LR/Element.h"
#include "../../LR/Closure.h"
#include "../../LR/Kernel.h"
#include "../../LR/PowersetAlgo.h"


#include "ElementLR1.h"
#include "PowersetAlgoLR1.h"

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
using std::queue;
using std::pair;


ElementLR1* PowersetAlgoLR1::map_new_element(ProductionRule PR, Terminal T, int idx_point)
{
    if( !parts_to_element.count({PR, T, idx_point}) )
    {
        ElementLR1 *ELR1 = new ElementLR1(PR, T, idx_point);
        parts_to_element[{PR, T, idx_point}] = ELR1;
    }
    return parts_to_element[{PR, T, idx_point}];
}

set<Element*> PowersetAlgoLR1::get_move(set<Element*> elements, Symbol S)
{
    set<Element*> element_reachables;

    for(Element *E: elements)
    {
        ElementLR1 *ELR1 = (ElementLR1*) E;
        ProductionRule PR = ELR1->get_production();
        Terminal lookahead = ELR1->get_lookahead();

        if(ELR1->get_idx_point()+1 < PR.get_sz() && PR.get_symbol_right( ELR1->get_idx_point()+1) == S)
        {
            ProductionRule new_PR = ELR1->get_production();
            int idx_point = ELR1->get_idx_point();
            new_PR.erase_symbol_by_idx(idx_point);

            ElementLR1 *new_element = map_new_element(new_PR, lookahead, idx_point+1);
            element_reachables.insert(new_element);
        }
    }

    return element_reachables;
}

Closure PowersetAlgoLR1::get_closure(Kernel K)
{
    Closure Closure_p(K);


    queue< Element* > q_bfs;
    for(Element* E: K)
        q_bfs.push(E);


    set< ElementLR1* > elem_processed;
    while(!q_bfs.empty())
    {
        ElementLR1* curr = (ElementLR1*) q_bfs.front(); q_bfs.pop();
        ProductionRule PR = curr->get_production();
        Terminal lookahead = curr->get_lookahead();


        vector<Symbol> beta = get_symbols_slice(PR, curr->get_idx_point()+2);
        beta.push_back(lookahead);
        First First_lookahead = FirstFact.get_first(beta);


        if(curr->get_idx_point()+1  < PR.get_sz() )
        {

            Symbol S = PR.get_symbol_right( curr->get_idx_point() + 1 );
            
            if( !S.is_terminal() )
            {
                vector<int> productions_of_s = G.get_idx_productions_of_nt(S);

                for(int idx_production: productions_of_s )
                {
                    ProductionRule PR_S = G.get_production_rule(idx_production);

                    for(Terminal b: First_lookahead)
                    {
                        ElementLR1 *new_element = map_new_element(PR_S, b);
                        if(elem_processed.count(new_element)) continue;
                        
                        elem_processed.insert(new_element);
                        Closure_p.insert(new_element);
                        q_bfs.push(new_element);
                    }
                }
            }
        }
    }   
    return Closure_p;
}


vector<Symbol> PowersetAlgoLR1::get_symbols_slice(ProductionRule PR, int idx_left, int idx_right)
{
    int n_PR = PR.get_sz();
    if(idx_right == -1) idx_right = n_PR-1;

    vector<Symbol> symbols;
    for(int i = idx_left; i <= idx_right; i++) symbols.push_back(PR.get_symbol_right(i));

    return symbols;
}
