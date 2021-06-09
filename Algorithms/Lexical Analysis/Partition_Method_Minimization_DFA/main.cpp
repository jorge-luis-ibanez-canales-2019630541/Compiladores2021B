#include <iostream>
#include "../Automaton/DFA.h"
#include "../RE_to_DFA_Syntax_Tree/src/AlgoREtoDFA.h"
#include "../Automaton/GV.h"
#include "src/PartitionAlgo.h"

using namespace std;


int main () {
	//fastIO();

    Regex regex; cin>>regex;


    //Para crear un DFA
    AlgoREtoDFA R(regex);
    DFA* A = R.run();



    //Para minimizar el DFA
    PartitionAlgo P(A);
    auto B = P.run();


    GV *GraphViz = new GV();    
    cout << GraphViz->get_gv(B,regex.get_regex()) << endl;
    

	return 0;
}