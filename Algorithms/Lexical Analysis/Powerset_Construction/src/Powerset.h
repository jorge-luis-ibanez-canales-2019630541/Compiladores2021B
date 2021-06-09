#ifndef _POWERSET_
#define _POWERSET_

#include<set>
#include "../../Automaton/State.h"

using std::set;

class Powerset{
    private:
        set<State*> powerset;

    public:
        Powerset() {}
        Powerset(set<State*> powerset): powerset(powerset) {}
        set<State*> get_powerset();        
        
        int count(State* S);
        int size();

        void insert(State* S);
        
        bool operator<(const Powerset &P)const;

};

#endif