#include<map>
#include<set>
#include "SyntaxTree.h"
#include "SyntaxTreeAlgo.h"
#include "../../Automaton/State.h"
#include "../../Automaton/DFA.h"
#include "AlgoREtoDFA.h"
#include<queue>

using std::set;
using std::map;
using std::queue;

/*
Si es * o eps, es nullable por definicion
Si es |, con que tenga un nullable ya lo hace nullable
si es ., los dos tienen que ser nullable para que sea nullable

si es *, el inicio y final es el inicio y final de su hijo
si es |, el inicio el final es la union del inicio y el final de sus hijos
Si es ., el inicio es el de la izq y, si es nullable, tambien puede ser el hijo de la derecha
            el final es el de la der, y si es nullable, tambien puede ser el del hijo de la izquierda
*/

void AlgoREtoDFA::dfs_get_nullable(NodeAlgo *curr)
{
    if(curr->is_leaf()) return; //Ya tiene toda la informacion

    if(curr->has_left()) dfs_get_nullable(curr->get_left());
    if(curr->has_right()) dfs_get_nullable(curr->get_right());


    if(curr->get_val() == '|')
    {
        if(curr->get_left()->is_nullable() || curr->get_right()->is_nullable()) curr->set_nullable(true); //nullable
    }
    else if(curr->get_val() == '.')
    {
        if(curr->get_left()->is_nullable() && curr->get_right()->is_nullable()) curr->set_nullable(true); //nullable
        
    }
    else //curr->get_val() == '.'
    {
        //Ya es nullable por definicion
    }

}

void AlgoREtoDFA::dfs_get_starting(NodeAlgo *curr)
{
    if(curr->is_leaf()) return; //Ya tiene toda la informacion


    if(curr->has_left()) dfs_get_starting(curr->get_left());
    if(curr->has_right()) dfs_get_starting(curr->get_right());
    
    if(curr->get_val() == '|')
    {

        set<int> startingL = curr->get_left()->get_starting();
        set<int> startingR = curr->get_right()->get_starting();
        startingL.insert(startingR.begin(), startingR.end()); // Merge
        curr->set_starting(startingL); //Starting

    }
    else if(curr->get_val() == '*')
    {
        curr->set_starting(curr->get_left()->get_starting()); //Starting
    }
    else //curr->get_val() == '.'
    {
        set<int> startingL = curr->get_left()->get_starting();
        if(curr->get_left()->is_nullable())
        {
            set<int> startingR = curr->get_right()->get_starting();
            startingL.insert(startingR.begin(), startingR.end());
        }
        curr->set_starting(startingL); //Starting
    }
}

void AlgoREtoDFA::dfs_get_ending(NodeAlgo *curr)
{
    if(curr->is_leaf()) return; //Ya tiene toda la informacion


    if(curr->has_left()) dfs_get_ending(curr->get_left());
    if(curr->has_right()) dfs_get_ending(curr->get_right());
    
    if(curr->get_val() == '|')
    {

        set<int> endingL = curr->get_left()->get_ending();
        set<int> endingR = curr->get_right()->get_ending();
        endingL.insert(endingR.begin(), endingR.end());
        curr->set_ending(endingL); //Ending

    }
    else if(curr->get_val() == '*')
    {
        curr->set_ending(curr->get_left()->get_ending()); //Ending
    }
    else //curr->get_val() == '.'
    {

        set<int> endingR = curr->get_right()->get_ending();
        if(curr->get_right()->is_nullable())
        {
            set<int> endingL = curr->get_left()->get_ending();
            endingR.insert(endingL.begin(), endingL.end());
        }
        curr->set_ending(endingR); //Ending

    }
}

void AlgoREtoDFA::dfs_get_follow(NodeAlgo *curr, map<int, set<int>> &table_follow)
{
    if(curr->is_leaf()) return;

    if(curr->has_left()) dfs_get_follow(curr->get_left(), table_follow);
    if(curr->has_right()) dfs_get_follow(curr->get_right(), table_follow);

    set<int> ending_f, starting_f;

    if(curr->get_val() == '*') //a los del final les sigue los del inicio
    {
        ending_f = curr->get_ending();
        starting_f = curr->get_starting();
        
    }
    else if(curr->get_val() == '.') //A los del final del izquierdo les sigue los del inicio de la derecha
    {
        ending_f = curr->get_left()->get_ending();
        starting_f = curr->get_right()->get_starting();
    }

    for(int id_end: ending_f)
        for(int id_start: starting_f)
            table_follow[id_end].insert(id_start);

    return;
}


DFA* AlgoREtoDFA::run()
{
    //Getting info
    dfs_get_nullable(ST->get_root());
    dfs_get_starting(ST->get_root());
    dfs_get_ending(ST->get_root());
    map<int, set<int>> table_follow;
    dfs_get_follow(ST->get_root(), table_follow);


    //Creating equivalent DFA
    DFA *DFA1 = new DFA();
    set<int> set_start = ST->get_root()->get_starting();
    State *start_DFA = map_set(set_start);
    DFA1->set_start(start_DFA);

    
    queue<State*> q_bfs;
    set<State*> processed;

    q_bfs.push(start_DFA);
    processed.insert(start_DFA);

    while(!q_bfs.empty())
    {
        State *curr = q_bfs.front(); q_bfs.pop();

        for(char symb: DFA1->alph) 
        {
            set<int> id_reachables;
            for(int id_inset: state_to_set[curr])
            {
                if(ST->get_val(id_inset) == symb)
                {
                    set<int> follow_id = table_follow[id_inset];
                    id_reachables.insert( follow_id.begin(), follow_id.end() );
                }
            }
            State *new_state = map_set(id_reachables);

            if(!is_void_state(new_state))
                curr->make_trans(new_state, symb);

            if(processed.count(new_state)) continue;
            
            q_bfs.push(new_state);
        }
        processed.insert(curr);
    }
    
    for(auto state_set: state_to_set)
    {
        State* S = state_set.first;
        if(is_final_state(S))
            DFA1->insert_final(S);
    }

    return DFA1;
}




State* AlgoREtoDFA::map_set(const set<int> &set_ST)
{
    if(!set_to_state.count(set_ST))
    {
        State* new_state = new State(id_DFA++);
        set_to_state[set_ST] = new_state;
        state_to_set[new_state] = set_ST;
    }
    return set_to_state[set_ST];
}

bool AlgoREtoDFA::is_void_state(State *S) { return state_to_set[S].size() == 0; }

bool AlgoREtoDFA::is_final_state(State *S)
{
    for(int id_inset: state_to_set[S])
        if(ST->get_val(id_inset) == '#') 
            return true;
    
    return false;
}