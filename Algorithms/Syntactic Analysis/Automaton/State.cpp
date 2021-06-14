#include "State.h"

int State::get_id(){ return id; }
set<State*> State::query_trans(char label){ return trans[label]; }
map<char, set<State*>> State::get_trans(){ return trans; }


void State::set_id(int id){ this->id = id; }


void State::make_trans(State *dest, char label){ trans[label].insert(dest); }
void State::copy_trans(State *S) { trans = S->get_trans(); }