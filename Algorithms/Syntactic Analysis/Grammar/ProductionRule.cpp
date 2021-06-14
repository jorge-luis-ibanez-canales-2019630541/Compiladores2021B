#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Symbol.h"

#include "ProductionRule.h"

using std::vector;
using std::string;
using std::istream;
using std::ostream;


ProductionRule::ProductionRule(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    int n_str = str.size();
    left_part = str[0];

    //assert(n_str >= 4);

    for(int i = 3; i<n_str; i++)
    {
        char curr = str[i];
        if( isupper(curr) ) right_part.push_back(NonTerminal(curr));
        else right_part.push_back(Terminal(curr)) ;
    }   
}


NonTerminal ProductionRule::get_left_part() { return left_part;  }
vector<Symbol> ProductionRule::get_right_part() { return right_part; }
Symbol ProductionRule::get_symbol_right(int idx) { return right_part[idx]; }
int ProductionRule::get_sz() { return right_part.size(); }


void ProductionRule::set_left_part(NonTerminal NT) { left_part = NT; }
void ProductionRule::set_right_part(vector<Symbol> vs) { right_part = vs; }


void ProductionRule::erase_symbol_by_idx(int idx) { right_part.erase(right_part.begin() + idx); }
void ProductionRule::insert_symbol_by_idx(int idx, Symbol S) { right_part.insert(right_part.begin() + idx, S); }






bool ProductionRule::operator==(const ProductionRule &PR) const{
    return left_part == PR.left_part && right_part == PR.right_part;
}

bool ProductionRule::operator<(const ProductionRule &PR) const{
    return right_part < PR.right_part || (right_part == PR.right_part && left_part < PR.left_part);
}


ostream &operator<<(ostream &os, const ProductionRule & PR)
{
    os << PR.left_part << " -> ";
    for(auto x: PR.right_part) os << x << " " ;
    return os;
}

