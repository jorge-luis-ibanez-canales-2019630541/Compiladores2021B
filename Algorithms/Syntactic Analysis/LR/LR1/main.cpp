#include <bits/stdc++.h>

//Grammar
#include "../../Grammar/Grammar.h"
#include "../../Grammar/ProductionRule.h"
#include "../../Grammar/Symbol.h"

//Automaton
#include "../../Automaton/NFA.h"
#include "../../Automaton/DFA.h"
#include "../../Automaton/State.h"
#include "../../Automaton/GV.h"

//LR
#include "../LR/Closure.h"
#include "../LR/Element.h"
#include "../LR/Kernel.h"
#include "../LR/PowersetAlgo.h"
#include "../LR/TableLR.h"

//LR0
#include "src/ElementLR1.h"
#include "src/PowersetAlgoLR1.h"
#include "src/TableLR1.h"


using namespace std;


int main () {
	//fastIO();

    ProductionRule PR1("F->cBB");
    ProductionRule PR2("B->aB");

    ProductionRule PR3("B->b");
    //ProductionRule PR4("T->F");
    //ProductionRule PR5("F->(E)");
    //ProductionRule PR6("F->i");
    
    Grammar G(NonTerminal("F"), { PR1, PR2, PR3});



    TableLR1 TLR1(G);


    TLR1.print();


	return 0;
}

