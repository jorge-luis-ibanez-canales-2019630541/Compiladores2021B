#include <map>
#include <set>

#include "State.h"
#include "NFA.h"

using std::map;
using std::set;


State* NFA::get_start(){ return start; }
State* NFA::get_final(){ return *(finales.begin());   }
set<State*> NFA::get_finales(){ return finales; }
int NFA::get_sz() { return sz_NFA; }

void NFA::set_start(State *start){ this->start = start; } //A lo mejor es bueno usar un free
void NFA::insert_final(State *final){ this->finales.insert(final); } 
void NFA::delete_final(State *final){ this->finales.erase(final);   };
void NFA::delete_finales(){ this->finales.clear(); }
void NFA::set_sz(int sz_NFA){ this->sz_NFA = sz_NFA; };

void NFA::dfs(State *current, map< State*, map<char, set<State*>>> &ans)
{
    if(ans.count(current)) return;
    current->set_id(++sz_NFA);
    ans[current] = current->get_trans();
    for(auto por_char: ans[current])
        for(auto E: por_char.second)
            dfs(E, ans);
}
map< State*, map<char, set<State*>>> NFA::get_trans()
{
    this->sz_NFA = 0;
    map< State*, map<char, set<State*>>> ans;
    dfs(this->start, ans);
    return ans;
}

