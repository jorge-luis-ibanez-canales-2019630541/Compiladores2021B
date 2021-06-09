#include "Powerset.h"
#include <set>


using std::set;

set<State*> Powerset::get_powerset() { return powerset; }



int Powerset::count(State* S) { return powerset.count(S); }
int Powerset::size() { return powerset.size(); } 

void Powerset::insert(State* S) { powerset.insert(S); }

bool Powerset::operator<(const Powerset &P) const {  return powerset < P.powerset;   }
