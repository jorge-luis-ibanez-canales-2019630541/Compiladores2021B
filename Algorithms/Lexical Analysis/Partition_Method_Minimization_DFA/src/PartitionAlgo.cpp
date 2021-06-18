#include "PartitionAlgo.h"
#include "../../Automaton/State.h"
#include "../../Automaton/DFA.h"
#include "Partition.h"
#include "UnionFind.cpp"


bool PartitionAlgo::are_distinct(State* node_u, State* node_v)
{
    for(char c: DFA_S->alph)
    {
        State* move_u = *((node_u->query_trans(c)).begin());
        State* move_v = *((node_v->query_trans(c)).begin());

        if(state_to_idclass[move_u] != state_to_idclass[move_v]) //Llevan a distintas clases
            return true;
    }
    return false;
}

vector<EquivClass> PartitionAlgo::partition_class(EquivClass EC)
{
    size_t n_states = EC.size();
    vector<State*> equiv_class_v;
    for(State* state_inclass: EC) //Lo transformo a vector para no tener que utilizar iteradores
        equiv_class_v.push_back(state_inclass);


    UnionFind<State*> UF(equiv_class_v);

    for(size_t i = 0; i<n_states; i++)
    {
        State* node_u = equiv_class_v[i];
        for(size_t j = i+1; j<n_states; j++)
        {
            State* node_v = equiv_class_v[j];
            if(UF.areConnected(node_u, node_v)) continue; //Ya forman parte de la misma clase en la nueva particion

            if(!are_distinct(node_u, node_v))
                UF.join(node_u, node_v);
        }
    }


    vector<EquivClass> new_equiv_classes(UF.numberOfSets());
    int id_in_equiv_class = 0;
    map<State*, int> id_roots;

    for(size_t i = 0; i<n_states; i++)
    {
        State* node_u = equiv_class_v[i];
        State* dad = UF.root(node_u);
        if( !id_roots.count(dad) ) id_roots[dad] = id_in_equiv_class++;
        new_equiv_classes[id_roots[dad]].insert(node_u);
    }
    return new_equiv_classes;
}

DFA* PartitionAlgo::construct_DFA(Partition partition)
{
    DFA* A1 = new DFA();

    int n_states_dfa = partition.size();
    int id_dfa = 1;


    map<State*, State*> map_to_dfa; //Cada estado en una clase de equivalencia se mapea a un estado del DFA
    for(EquivClass equiv_class: partition)
    {
        State* new_state_dfa = new State(id_dfa++);
        for(State* St: equiv_class)
        {
            map_to_dfa[St] = new_state_dfa;
        }
    }

    for(EquivClass equiv_class: partition)
    {
        State* rep_equiv_class = *(equiv_class.begin());
        State* new_state_dfa = map_to_dfa[rep_equiv_class];

        for(auto trans: all_trans[rep_equiv_class])
        {
            char label = trans.first;
            State* state_moving = *(trans.second.begin());
            new_state_dfa->make_trans( map_to_dfa[state_moving], label  );
        }
    }



    State* initial = DFA_S->get_start();
    set<State*> finales = DFA_S->get_finales();

    
    A1->set_start( map_to_dfa[initial]  );
    for(State* final: finales)
        A1->insert_final(map_to_dfa[final]);

    return A1;
}

Partition PartitionAlgo::get_initial_partition()
{
    Partition initial_partition;

    EquivClass non_finales;
    EquivClass finales( DFA_S->get_finales()  );

    for(auto state_trans: all_trans)
    {
        State* st = state_trans.first;
        if(!finales.is_inside(st))
        {
            non_finales.insert(st);
            state_to_idclass[st] = 0;
        } 
        else
            state_to_idclass[st] = 1;
    }
    initial_partition.push(non_finales);
    initial_partition.push(finales);


    return initial_partition;
}

DFA* PartitionAlgo::run( )
{
    Partition initial_partition = get_initial_partition();
    Partition new_partition = initial_partition, last_partition;

    do
    {
        last_partition = new_partition;
        new_partition.clear();

        for(EquivClass equiv_class: last_partition)
        {
            if(equiv_class.size() <= 1)
            {
                new_partition.push(equiv_class);
                continue;
            } 

            auto new_equiv_classes =  partition_class(equiv_class);

            for(set<State*> new_equiv_class: new_equiv_classes)
            {
                new_partition.push(new_equiv_class); 
            }
        }

        size_t n_equiv_classes = new_partition.size();
        for(size_t i = 0; i<n_equiv_classes; i++)
        {
            set<State*> equiv_class = new_partition[i];
            for(State* st: equiv_class)
            {
                state_to_idclass[st] = i;
            }
        }
    }while(last_partition != new_partition);


    return construct_DFA(new_partition);
}