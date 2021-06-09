#ifndef _GRAMMAR_
#define _GRAMMAR_

#include "Symbol.h"
#include "ProductionRule.h"
#include <set>
#include <vector>


using std::set;
using std::vector;


class Grammar{
    private:
        NonTerminal start;
        set<Terminal> terminals;
        set<NonTerminal> non_terminals;
        vector< ProductionRule > production_rules;


    public:
        

        Grammar() { }
        Grammar(NonTerminal start, vector< ProductionRule > production_rules ): start(start), production_rules(production_rules) { get_info_symbols(); }

        void get_info_symbols();


        NonTerminal get_start() const;
        set<Terminal> get_terminals() const;
        set<NonTerminal> get_non_terminals() const;
        vector<ProductionRule> get_production_rules() const;
        ProductionRule get_production_rule(int id) const;
        int get_sz() const;

        bool operator==(const Grammar G) const;

        //friend istream& operator>>(istream&, Grammar&);
        friend ostream& operator<<(ostream&, const Grammar&);
};


#endif