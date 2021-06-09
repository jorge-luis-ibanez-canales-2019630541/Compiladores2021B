#include "Closure.h"
#include "../../Automaton/State.h"
#include <queue>

using std::queue;

Closure::Closure(set<State*> kernel): kernel(kernel)
{
    queue<State*> q_bfs;

    for(State* start: kernel)
    {
        q_bfs.push(start);
        closure.insert(start);
    }
    while(!q_bfs.empty())
    {
        State* curr = q_bfs.front(); q_bfs.pop();
        for(State* new_state: curr->query_trans(eps))
        {
            if(closure.count(new_state)) continue;
            closure.insert(new_state);
            q_bfs.push(new_state);
        }
    }
}


set<State*> Closure::get_kernel() { return kernel; }
Powerset Closure::get_closure() { return closure; }

int Closure::size() { return closure.size(); }
int Closure::count(State *S) { return closure.count(S);  }

bool Closure::operator<(const Closure &C) const {  return closure < C.closure;  }