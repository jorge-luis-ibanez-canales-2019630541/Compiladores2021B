#include <iostream>
#include "../Automaton/NFA.h"
#include "../Automaton/Regex.h"
#include "../Automaton/GV.h"
#include "src/ThompsonAlgo.h"

using namespace std;


int main () {
    Regex Re; cin>>Re;    


    ThompsonAlgo T(Re);
    NFA* A = T.run();    


    GV *GraphViz = new GV();
    cout << GraphViz->get_gv(A, Re.get_regex()) << endl;
    
	return 0;
}
