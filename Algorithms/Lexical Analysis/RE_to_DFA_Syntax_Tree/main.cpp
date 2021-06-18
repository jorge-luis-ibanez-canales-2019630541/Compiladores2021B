#include <bits/stdc++.h>
#include "../Automaton/Regex.h"
#include "../Automaton/DFA.h"
#include "src/SyntaxTreeAlgo.h"
#include "src/AlgoREtoDFA.h"
#include "../Automaton/GV.h"

using namespace std;

//const char eps = "E";

int main () {
	
    Regex Re; cin>>Re;
    
    AlgoREtoDFA Algo(Re);

    DFA* A1 = Algo.run();

    GV *GV1 = new GV();
    cout << GV1->get_gv(A1, Re.get_regex()) << endl;
	return 0;
}

