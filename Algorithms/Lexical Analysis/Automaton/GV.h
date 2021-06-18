#ifndef _GV_
#define _GV_

#include <string>
#include <sstream>
#include "NFA.h"
//#include "../RE_to_DFA_Syntax_Tree/SyntaxTree.h"

using std::stringstream;
using std::string;

class SyntaxTree;
class Node;
class NFA;

class GV{
    private:

        void dfs_gv(Node* curr, stringstream &tree_gv, int &id_node); //Auxiliar fot get_gv of SyntaxTree
    public:
        string get_gv(NFA *NFA1, string title);

        string get_gv(SyntaxTree *ST, string title);
};


#endif