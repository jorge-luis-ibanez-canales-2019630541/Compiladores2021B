#ifndef _PRODUCTIONRULE_
#define _PRODUCTIONRULE_

#include <vector>
#include <string>
#include <iostream>
#include "Symbol.h"

using std::vector;
using std::string;
using std::istream;
using std::ostream;

class ProductionRule{
    private:
        NonTerminal left_part;
        vector< Symbol > right_part;

    public:
        ProductionRule() {}
        ProductionRule(NonTerminal left_part, vector<Symbol> right_part): left_part(left_part), right_part(right_part) {}

        ProductionRule(string str);

        NonTerminal get_left_part();
        vector<Symbol> get_right_part();
        Symbol get_symbol_right(int idx);
        int get_sz();


        void set_left_part(NonTerminal NT);
        void set_right_part(vector<Symbol> vs);
        void erase_symbol_by_idx(int idx);
        void insert_symbol_by_idx(int idx, Symbol S);

        bool operator==(const ProductionRule &PR) const;
        bool operator<(const ProductionRule &PR) const;


        //friend istream& operator>>(istream&, ProductionRule&);
        friend ostream& operator<<(ostream&, const ProductionRule&);
};


#endif