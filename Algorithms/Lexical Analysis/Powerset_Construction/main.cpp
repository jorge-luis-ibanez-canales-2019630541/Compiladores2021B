#include <iostream>
#include "src/PowersetConstruction.h"
#include "../Automaton/NFA.h"
#include "../Automaton/DFA.h"
#include "../Automaton/GV.h"
#include "../Thompson_Construction/src/ThompsonAlgo.h"

using namespace std;



int main () {
	//fastIO();
    //string cadena = "(ab*|c)*(da)*";

    Regex Re; cin>>Re;

    //To create NFA
    ThompsonAlgo T(Re);
    auto NFA1 = T.run();

    //To pass from NFA to DFA
    PowersetConstruction P(NFA1);
    auto DFA1 = P.run();    

    GV *GraphViz = new GV();

    cout << GraphViz->get_gv(DFA1,Re.get_regex()) << endl;

	return 0;
}