#include <bits/stdc++.h>

//Grammar
#include "../../Grammar/CyclesDetector.h"
#include "../../Grammar/First.h"
#include "../../Grammar/FirstFactory.h"
#include "../../Grammar/Follow.h"
#include "../../Grammar/FollowFactory.h"
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
#include "src/ElementLR0.h"
#include "src/PowersetAlgoLR0.h"
#include "src/TableLR0.h"

using namespace std;


int main () {
	//fastIO();

    ProductionRule PR1("E->E+T");
    ProductionRule PR2("E->T");
    ProductionRule PR3("T->T*F");
    ProductionRule PR4("T->F");
    ProductionRule PR5("F->(E)");
    ProductionRule PR6("F->i");
    
    Grammar G(NonTerminal("E"), { PR1, PR2, PR3, PR4, PR5, PR6 });

    TableLR0 TLR0(G);
    TLR0.print();

	return 0;
}

