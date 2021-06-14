#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <sstream>

#include "Element.h"
#include "Closure.h"
#include "Kernel.h"
#include "TableLR.h"

#include "../../Automaton/DFA.h"
#include "../../Automaton/State.h"

#include "../../Grammar/ProductionRule.h"
#include "../../Grammar/Grammar.h"
#include "../../Grammar/Symbol.h"

using std::vector;
using std::map;
using std::pair;
using std::string;
using std::stringstream;
using std::setw;
using std::setfill;
using std::endl;
using std::cout;



void TableLR::get_go_to()
{
    for(pair<int, State*> iS: id_to_state)
    {
        int id = iS.first;
        State* S = iS.second;

        for(NonTerminal NT: G.get_non_terminals())
        {
            if( S->query_trans(NT[0]).size() == 0 ) continue;
            State *R = *((S->query_trans(NT[0])).begin());
            go_to[{id, NT}] = R;
        }
    }
}



void TableLR::get_action_shifts()
{
    for(pair<int, State*> iS: id_to_state)
    {
        int id = iS.first;
        State* S = iS.second;

        for(Terminal T: G.get_terminals())
        {
            if( S->query_trans(T[0]).size() == 0 ) continue;
            State *R = *((S->query_trans(T[0])).begin());
            action[{id, T}] = {'s', R->get_id() };
        }
    }
}



void TableLR::get_action()
{
    get_action_shifts();
    get_action_accept();
    get_action_reduce();
}

void TableLR::get_table()
{
    get_go_to();
    get_action();
}

void TableLR::print()
{
    vector<Symbol> symbs;
    for(Terminal T: G.get_terminals())
        symbs.push_back(T);

    symbs.push_back(Terminal("$"));

    for(NonTerminal NT: G.get_non_terminals())
        symbs.push_back(NT);


    //int cols = symbs.size() + 1;
    int rows = state_to_closure.size();

    int width = 13;
    char filler = ' ';

    //TITLE
    cout << setw(width + 7) << setfill(filler);
    for(Symbol S: symbs) 
        cout << S << setw(width) << setfill(filler);
    cout << endl;


    for(int i = 1; i <= rows; i++)
    {
        cout <<  print_row(i, width, filler, symbs) << endl;
    }
}


string TableLR::print_row(int i, int width, char filler, vector<Symbol> symbs)
{
    stringstream ss; ss << setw(7) << i << setw(width) << setfill(filler);
    for(Symbol S: symbs)
    {
        if(S.is_terminal())
        {
            if(action.count({i,S}))
                ss << action[{i,S}].first << action[{i,S}].second;
            else
                ss << " ";
        }
        else
        {
            if(go_to.count({i,S}))
                ss << go_to[{i,S}]->get_id();
            else
                ss << " ";
        }
        ss << setw(width) << setfill(filler);
            
    }
    return ss.str();
}



