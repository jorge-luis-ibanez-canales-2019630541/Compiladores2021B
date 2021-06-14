#ifndef _TABLELR_
#define _TABLELR_

#include <map>
#include <utility>
#include <string>

#include "Element.h"
#include "Closure.h"
#include "Kernel.h"

#include "../../Automaton/DFA.h"
#include "../../Automaton/State.h"

#include "../../Grammar/ProductionRule.h"
#include "../../Grammar/Grammar.h"
#include "../../Grammar/Symbol.h"


using std::map;
using std::pair;
using std::string;

class TableLR{
    protected:
        Grammar G;
        map< pair<int, NonTerminal> , State* > go_to;
        map< pair<int, Terminal> , pair<char, int> > action;
        map<State*, Closure> state_to_closure; //Iniciar primero
        map< int, State*> id_to_state; //Iniciar primero
    
        void get_go_to(); 
        void get_action_shifts();
        virtual void get_action_accept() = 0; //Abstracto
        virtual void get_action_reduce() = 0; //Abstracto

        void get_action();
        void get_table();
        string print_row(int i, int width, char filler, vector<Symbol> symbs);

    public:

        TableLR(){}
        TableLR(Grammar G): G(G) {}
        
        
        void print();
};



#endif