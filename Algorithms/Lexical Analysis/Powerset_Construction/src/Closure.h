#ifndef _CLOSURE_
#define _CLOSURE_


#include<set>
#include<map>
#include<vector>
#include "Powerset.h"

using std::vector;
using std::set;
using std::map;


class Closure{
    private:
        Powerset closure;
        set<State*> kernel;

    public:
        Closure() {}
        Closure(set<State*> kernel);
        set<State*> get_kernel();
        Powerset get_closure();

        int count(State *S);
        int size();


        bool operator<(const Closure &C) const;

};

#endif