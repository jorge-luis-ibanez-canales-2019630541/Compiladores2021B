#ifndef _FIRSTFACTORY_
#define _FIRSTFACTORY_


#include "Grammar.h"
#include "CyclesDetector.h"
#include "First.h"
#include "Symbol.h"
#include "ProductionRule.h"


class FirstFactory{
    private:

        Grammar G;
        CyclesDetector<int> CD;

        First do_rule1(Terminal T);

        First do_rule2(NonTerminal NT);
        First do_second_per_production(ProductionRule PR);

        First do_rule3(Symbol S); //Asumir que S = epsilon

        First do_rule4(vector<Symbol> Ss);

    public:

        FirstFactory(){ }
        FirstFactory(Grammar G): G(G) {  }
 
        First get_first(Symbol S);

        First get_first(vector<Symbol> S);
};


#endif