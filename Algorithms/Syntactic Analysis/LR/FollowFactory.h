#ifndef _FOLLOWFACTORY_
#define _FOLLOWFACTORY_

#include <vector>
#include "Grammar.h"
#include "CyclesDetector.h"
#include "FirstFactory.h"
#include "Symbol.h"
#include "ProductionRule.h"
#include "Follow.h"
#include <utility> //para pair

using std::vector;
using std::pair;

class FollowFactory{
    private:
        Grammar G;
        FirstFactory FirstFact;
        CyclesDetector<pair<int,int>> CD;

        Follow try_rule1(NonTerminal NT);
        Follow try_rule2(int idx_finded, ProductionRule PR, int id_pr);
        Follow try_rule3(int idx_finded, ProductionRule PR, int id_pr);



        vector<int> find_symbol(NonTerminal NT, vector<Symbol> Symbols);
        vector<Symbol> get_symbols(ProductionRule PR, int idx_left, int idx_right);

    public:
        FollowFactory() { }
        FollowFactory(Grammar G): G(G) { FirstFact = FirstFactory(G); }

        Follow get_follow(NonTerminal NT);
};

#endif