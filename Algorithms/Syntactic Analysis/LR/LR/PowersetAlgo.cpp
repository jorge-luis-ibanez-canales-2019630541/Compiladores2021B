#include <vector>
#include <set>
#include <map>
#include <queue>

#include "Element.h"
#include "PowersetAlgo.h"
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


PowersetAlgo::PowersetAlgo(Grammar G): G(G){
    for(Terminal T: G.get_terminals())
        all_symbs.push_back(T);
    for(NonTerminal NT: G.get_non_terminals())
        all_symbs.push_back(NT);
}


State* PowersetAlgo::map_to_state(Closure C)
{
    if(!closure_to_state.count(C))
    {
        State* new_state = new State(id_DFA);
        id_to_state[id_DFA++] = new_state;
        closure_to_state[C] = new_state;
        state_to_closure[new_state] = C;
    }
    return closure_to_state[C];
}


void PowersetAlgo::get_powersets(Element* Start)
{
    DFA_F = new DFA();


    Closure C_start = get_closure(Kernel({Start}));
    State* start_state = map_to_state(C_start);
    DFA_F->set_start(start_state);


    queue<State*> q_bfs;
    set<State*> processed;
    q_bfs.push(start_state);        

    while(!q_bfs.empty())
    {
        State* curr = q_bfs.front(); q_bfs.pop();


        Closure aux = state_to_closure[curr];

        for(Symbol S: all_symbs)
        {
            
            Kernel K = get_move(state_to_closure[curr].get_elements() , S);
            
            if(K.size() == 0) continue;

            
            Closure C = get_closure(K);
            
            State* mapped_state = map_to_state(C);   
            
            curr->make_trans(mapped_state, S[0]); //Solo funciona con simbolos de sz = 1

            if(!processed.count(mapped_state))
                q_bfs.push(mapped_state);

        }
        
        processed.insert(curr);
    }
}

map< Closure, State* > PowersetAlgo::get_map_closure_to_state() { return closure_to_state; }
map< State*, Closure > PowersetAlgo::get_map_state_to_closure() { return state_to_closure; }
map< int, State*> PowersetAlgo::get_map_id_to_state() { return id_to_state; }

