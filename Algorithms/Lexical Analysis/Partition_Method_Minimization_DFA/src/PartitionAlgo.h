#ifndef _PARTITIONALGO_
#define _PARTITIONALGO_

#include<set>
#include<vector>
#include "../../Automaton/DFA.h"
#include "../../Automaton/State.h"
#include "../../Automaton/NFA.h"
#include "Partition.h"
#include "EquivClass.h"

using std::set;
using std::vector;

class PartitionAlgo{
    private:
        DFA *DFA_S;

        map< State*, int > state_to_idclass; //Para saber en qué indice esta el conjunto en el que se encuentra
        map<State*, map<char, set<State*>> > all_trans;
        

    public:
        PartitionAlgo(DFA *DFA_Ss) { DFA_S = DFA_Ss; all_trans = DFA_S->get_trans();  }

        bool are_distinct(State* node_u, State* node_v);
        vector<EquivClass> partition_class(EquivClass EC);
        DFA* construct_DFA(Partition partition);
        Partition get_initial_partition();
        DFA* run();
        

};

#endif