#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include "../../Grammar/Grammar.h"
#include "TableLL1.h"
#include "AnalyzerLL1.h"

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;

string AnalyzerLL1::analyze_string(string string_tocheck)
{
    string_tocheck.erase(remove(string_tocheck.begin(), string_tocheck.end(), ' '), string_tocheck.end());

    //cout << string_tocheck << "\n";

    vector<Symbol> string_vs;
    for(auto c: string_tocheck) string_vs.push_back(Symbol(c));
    
    return analyze_string(string_vs);
}


string AnalyzerLL1::analyze_string(vector<Symbol> string_tocheck)
{
    if(!Table.is_LL1())
        return "La gramatica no es LL1";

    string_tocheck.push_back(Terminal("$"));
    stack<Symbol> sstack; 

    sstack.push(Terminal("$"));
    sstack.push(G.get_start());

    int ip = 0;
    Symbol symbol_pointing = string_tocheck[ip];
    

    while( !sstack.empty() )
    {
        Symbol symbol_pointing = string_tocheck[ip];
        Symbol Top = sstack.top();    
        
        if(Top.is_epsilon())
        {
            sstack.pop();
            continue;
        }
        if(Top.is_terminal())
        {
            if(Top == symbol_pointing)
            {
                ip++;
                sstack.pop();
            }
            else
            {
                //! ERROR
                cout << "Algo paso aqui " << Top << " - " << symbol_pointing << "\n";
                return "No pertenece";
            }
        }
        else
        {
            if( Table.check_entry(Top, symbol_pointing) )
            {
                int id_production = Table.get_query({Top, symbol_pointing});
                sstack.pop();
                ProductionRule PR = G.get_production_rule(id_production-1);

                int n_PR = PR.get_sz();
                for(int i = n_PR-1; i >= 0; i--)
                    sstack.push(PR.get_symbol_right(i));
            }
            else
            {
                //! ERROR
                cout << "Algo paso aqui, no existe la entrada en la tabla [" << Top << ", " << symbol_pointing << "]\n";
                return "No pertenece";
            }
        }
    }
    

    return "Si pertenece";
}
