#include <map>
#include <utility>
#include <iostream>
#include "../../Grammar/Symbol.h"
#include "../../Grammar/Grammar.h"
#include "../../Grammar/FirstFactory.h"
#include "../../Grammar/FollowFactory.h"
#include "TableLL1.h"

using std::map;
using std::pair;
using std::cout;


void TableLL1::get_table()
{
    FirstFactory FirstFact(G);
    FollowFactory FollowFact(G);

    int n_rules = G.get_sz();

    for(int id = 1; id<=n_rules; id++) // A -> alpha
    {
        ProductionRule PR = G.get_production_rule(id-1);
        NonTerminal A = PR.get_left_part();
        vector<Symbol> alpha = PR.get_right_part();

        First First_alpha = FirstFact.get_first(alpha);

        for(Terminal a: First_alpha)
            if( !a.is_epsilon() )
                insert_entry(A,a,id);
                //table[{A,a}] = id;

        if(First_alpha.is_inside(epsilon))
        {
            Follow Follow_A = FollowFact.get_follow(A);
            for(Terminal b: Follow_A)
                if( !b.is_epsilon() )
                    insert_entry(A, b, id);
                    //table[{A,b}] = id;

            if(Follow_A.is_inside(Terminal("$")))
                insert_entry(A, Terminal("$"), id);
                //table[{A,Terminal("$")}] = id;
        }

    }
    return;
}


void TableLL1::insert_entry(NonTerminal NT, Terminal T, int id_rule)
{
    if(table.find({NT, T}) != table.end() )
        LL1 = false;
    
        
    table[{NT, T}] = id_rule;
    return;
}


bool TableLL1::check_entry(NonTerminal NT, Terminal T) { return table.count({NT, T}); }

int TableLL1::get_query(pair<NonTerminal, Terminal> query){ return table[query];  }
void TableLL1::print()
{
    set<Terminal> terminals = G.get_terminals(); terminals.insert(Terminal("$"));
    terminals.erase(Terminal(epsilon));
    

    cout << "\t\t  ";
    for(Terminal T: terminals) cout << T << "    \t";
    cout << "\n";


    for(NonTerminal NT: G.get_non_terminals())
    {
        cout << NT << "\t|\t";
        for(Terminal T: terminals) 
        {
            if(table[{NT,T}])
                cout << "{ "<< table[{NT,T}] << " }\t";
            else
            cout << "{ "<< "-" << " }\t";
        }
        cout << "\n";
    }
    return;
}    

bool TableLL1::is_LL1() { return LL1; }
