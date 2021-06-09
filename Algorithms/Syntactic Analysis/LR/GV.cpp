#include "GV.h"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "NFA.h"
//#include "../RE_to_DFA_Syntax_Tree/SyntaxTree.h"

using std::vector;
using std::string;
using std::stringstream;


string GV::get_gv(NFA *NFA1, string title = "Automata") //Devuelve las aristas del grafo en formato .gv para usar dot
{
    stringstream graph_gv;
    graph_gv << "digraph G {\n\trankdir=LR;\n";    
    auto E_As = NFA1->get_trans();
    
    vector< vector<int> > all_edges; //all_edges[0] = {fuente, destino, label}

    for(auto E_A: E_As)
    {
        auto state_source = E_A.first;
        auto edges = E_A.second;
        for(auto label_states: edges)
        {
            auto label = label_states.first;
            for(auto state_dest: label_states.second)
            {
                all_edges.push_back({state_source->get_id(), state_dest->get_id(), (int)label}); //Guarda todas las edges en formato {origen, destino, etiqueta}
            }
        }
    }

    sort(all_edges.begin(), all_edges.end()); //Las ordena en orden de aparicion, para que el .gv las ordene mas bonito
    for(auto edge: all_edges)
    {
        graph_gv << "\t" << edge[0] << " -> " << edge[1] << " [label=\"" << (char)edge[2] << "\"]"<< "\n";
    }

    for(auto F: NFA1->get_finales())
    {
        graph_gv << "\t" << F->get_id() << " [peripheries=2]"<<"\n";
    }

    graph_gv << "\t\" \" [shape=plaintext]" << "\n";
    graph_gv << "\t\" \" -> 1 [label=\"start\"]" << "\n";
    
    graph_gv << "\tlabelloc=\"t\";" << "\n";
    graph_gv << "\tlabel=\"" << title << "\";" << "\n";
    graph_gv << "}" << "\n";

    return graph_gv.str();
}


#ifdef _SYNTAXTREE_

void GV::dfs_gv(Node* curr, stringstream &tree_gv, int &id_node)
{
    int id_gv = ++id_node;
    tree_gv << "\t" << id_gv << " [label=\"" << curr->get_val() <<" \"];\n";

    if(curr->has_left())
    {
        tree_gv << "\t" << id_gv << " -> " << id_node+1 << "\n";
        dfs_gv(curr->get_left(), tree_gv, id_node);   
    }
    if(curr->has_right())
    {
        tree_gv << "\t" << id_gv << " -> " << id_node+1 << "\n";
        dfs_gv(curr->get_right(), tree_gv, id_node);
    }
}

string GV::get_gv(SyntaxTree *ST, string title = "Syntax Tree")
{
    stringstream tree_gv;
    tree_gv << "digraph G {\n";

    int id_node = 0;
    dfs_gv(ST->get_root(), tree_gv, id_node);

    tree_gv << "}\n";
    return tree_gv.str();
}

#endif
