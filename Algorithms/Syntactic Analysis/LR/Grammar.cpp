#include <set>
#include <vector>
#include "Symbol.h"
#include "ProductionRule.h"
#include "Grammar.h"
#include <iostream>

using std::set;
using std::vector;
using std::ostream;
using std::cout;


void Grammar::get_info_symbols()
{
    for(ProductionRule PR: production_rules)
    {
        non_terminals.insert(PR.get_left_part());
        for(Symbol S: PR.get_right_part())
        {
            if(S.is_terminal())
                terminals.insert(S);
            else
                non_terminals.insert(S);
        }
            
    }
}


NonTerminal Grammar::get_start() const { return start;  }
set<Terminal> Grammar::get_terminals() const { return terminals;  }
set<NonTerminal> Grammar::get_non_terminals() const { return non_terminals;  }
vector<ProductionRule> Grammar::get_production_rules() const { return production_rules;  }
ProductionRule Grammar::get_production_rule(int id) const { return production_rules[id]; }
int Grammar::get_sz() const { return production_rules.size(); }




bool Grammar::operator==(const Grammar G) const
{
    return start == G.start && terminals == G.terminals && non_terminals == G.non_terminals && production_rules == G.production_rules;
}

ostream &operator<<(ostream &os, const Grammar & G)
{
    os << "Start: " << G.get_start() << "\n";
    for(ProductionRule PR: G.get_production_rules()) cout << PR << "\n";
    return os;
}