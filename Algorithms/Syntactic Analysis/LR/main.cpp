#include <bits/stdc++.h>
#include "CyclesDetector.h"
#include "First.h"
#include "FirstFactory.h"
#include "Follow.h"
#include "FollowFactory.h"
#include "Grammar.h"
#include "ProductionRule.h"
#include "Symbol.h"
#include "NFA.h"
#include "DFA.h"
#include "State.h"

using namespace std;


struct Element{

    bool operator<(const Element &E) const { return this <  &E;  }
};


struct ElementLR0: Element{
    ProductionRule PR;
};

struct Kernel{
    set<Element> kernel;


    int size() { return kernel.size(); }

    Kernel() { }
    Kernel(set<Element> _kernel): kernel(_kernel) { }
};

struct Closure{
    Kernel kernel;
    set< Element > elements;


    set< Element > get_elements() {  return elements; }



    using iterator = set<Element>::iterator;
    iterator begin(){ return elements.begin(); }
    iterator end(){ return elements.end(); }
    bool operator<(const Closure &C) const { return this <  &C;  }
};



vector<Symbol> all_symbs = { Terminal('a'), Terminal('b'), Terminal('c'), NonTerminal('A'), NonTerminal('B'), NonTerminal('C')  };


struct PowersetAlgo{

    DFA *DFA_F;
    int id_DFA = 1;

    map< Closure, State* > closure_to_state;
    map< State*, Closure > state_to_closure;


    State* map_to_state(Closure C)
    {
        if(!closure_to_state.count(C))
        {
            State* new_state = new State(id_DFA++);
            closure_to_state[C] = new_state;
            state_to_closure[new_state] = C;
        }
        return closure_to_state[C];
    }


    set<Element> get_move(set<Element>, Symbol); //Abstracto
    Closure get_closure(Kernel); //Abstracto

    void get_powersets(Element Start)
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
};





int main () {
	//fastIO();



	return 0;
}

