#include<set>
#include<map>
#include<queue>
#include "../../Automaton/State.h"
#include "../../Automaton/NFA.h"
#include "../../Automaton/DFA.h"
#include "PowersetConstruction.h"
#include "Closure.h"
#include "Powerset.h"

using std::set;
using std::map;
using std::queue;


set<State*> PowersetConstruction::get_move(const set<State*> &T, char label)
{
    set<State*> states_reachables;

    for(State* state_in_set: T)
        for(State* state_moving_with_label: state_in_set->query_trans(label))
            states_reachables.insert(state_moving_with_label);
        
    
    return states_reachables;
}

bool PowersetConstruction::is_void_state(State *S){ return state_to_closure[S].size() == 0; }

bool PowersetConstruction::is_final_state(State *S)
{
    bool is_final = false;
    for(auto final_NFA: _NFA1->get_finales())
    {
        if(state_to_closure[S].count(final_NFA)) return true;
    }
    return false;
}

State* PowersetConstruction::map_closure(const Closure &closure)
{
    if(!closure_to_state.count(closure))
    {
        State* new_state = new State(id_DFA++);
        closure_to_state[closure] = new_state;
        state_to_closure[new_state] = closure;    
    }
    return closure_to_state[closure];
}

DFA* PowersetConstruction::run()
{
    auto DFA1 = new DFA();

    Closure closure_of_start({_NFA1->get_start()});
    State* start_DFA = map_closure(closure_of_start);
    DFA1->set_start(start_DFA);
    
    queue<State*> q_bfs;
    q_bfs.push(start_DFA);
    set<State*> processed;

    while(!q_bfs.empty())
    {
        State *current = q_bfs.front(); q_bfs.pop();

        for(char label: DFA1->alph)
        {
            set<State*> kernel = get_move(state_to_closure[current].get_closure().get_powerset(), label);
            Closure Closure1(kernel);
            //set<State*> new_state = get_closure(kernel);

            auto S = map_closure(Closure1);

            if(!is_void_state(S))
                current->make_trans(S, label);

            if(processed.count(S) || is_void_state(S)) continue;

            q_bfs.push(S);
        }
        processed.insert(current);
    }


    for(auto &state_closure: state_to_closure)
    {
        State* S = state_closure.first;
        if(is_final_state(S))
            DFA1->insert_final(S);
    }
    
    return DFA1;
}
